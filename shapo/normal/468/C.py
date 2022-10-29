#!/usr/bin/env python3

def sumfunc(k):
    return 45 * 10 ** (k - 1) * k

a = int(input())
val = sumfunc(18)
val %= a
rev = (a - val) % a
if rev == 0:
    print(1, 10 ** 18 - 1)
else:
    print(rev, 10 ** 18 + rev - 1)