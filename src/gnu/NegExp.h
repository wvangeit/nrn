// This may look like C code, but it is really -*- C++ -*-
/* 
Copyright (C) 1988 Free Software Foundation
    written by Dirk Grunwald (grunwald@cs.uiuc.edu)

This file is part of the GNU C++ Library.  This library is free
software; you can redistribute it and/or modify it under the terms of
the GNU Library General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your
option) any later version.  This library is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU Library General Public License for more details.
You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the Free Software
Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#ifndef _NegativeExpntl_h
#ifdef __GNUG__
//#pragma interface
#endif
#define _NegativeExpntl_h 1


//
//	Negative Exponential Random Numbers
//
// 

#include "Random.h"

class NegativeExpntl: public Random {
protected:
    double pMean;
public:
    NegativeExpntl(double xmean, RNG *gen);
    double mean();
    double mean(double x);

    virtual double operator()();
};


inline NegativeExpntl::NegativeExpntl(double xmean, RNG *gen)
: Random(gen) {
  pMean = xmean;
}

inline double NegativeExpntl::mean() { return pMean; }
inline double NegativeExpntl::mean(double x) {
  double t = pMean; pMean = x;
  return t;
}

#endif
