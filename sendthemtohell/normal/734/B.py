from math import *
from sys import *
from queue import *

a,b,c,d=(int(z) for z in input().split())
ans=0
ans+=256*min(a,c,d)
a-=min(a,c,d)
ans+=32*min(a,b)
print(ans)