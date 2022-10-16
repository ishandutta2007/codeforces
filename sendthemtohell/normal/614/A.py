from math import *
from sys import *
from decimal import *

l,r,k=(int(z) for z in stdin.readline().split())
k1=1
pr=0
while k1<=r:
    if k1>=l:
        stdout.write(str(k1)+" ")
        pr=1
    k1 *= k
if not pr:
    print(-1)
stdout.write("\n")