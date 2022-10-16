from sys import *
from decimal import *
from math import *
#from time import clock

#n=int(stdin.readline())
n,m=(int(z) for z in stdin.readline().split())
#arr=[int(z) for z in stdin.readline().split()]
#mat=[]
#for i in range(n):
#    mat.append([int(z) for z in stdin.readline().split()])
tim=240
tt=[5,10,15,20,25,30,35,40,45,50]
for i in range(n,-1,-1):
    if sum(tt[:i])+m<=tim:
        print(i)
        exit(0)
print(0)