#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input())
k = int(input())

arr = []
idx = 0
while k > 0:
    while 10 ** idx <= k and k % (10 ** idx) < n:
        idx += 1
    if k % (10 ** idx) >= n:
        idx -= 1
    while idx > 1 and k % (10 ** idx) == k % (10 ** (idx - 1)):
        idx -= 1
    arr.append(k % (10 ** idx))
    k //= (10 ** idx)
    idx = 0
mul = 1
sm = 0
for item in arr:
    sm += item * mul
    mul *= n
print(sm)