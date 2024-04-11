from math import *


a,b=(int(z) for z in input().split())
m=10*1000
hhh=int(input())
for i in range (hhh):
    x,y,v=(int(z) for z in input().split())
    m=min(m,((a-x)**2+(b-y)**2)**(0.5)/v)
print(m)