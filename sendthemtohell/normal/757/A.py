#from math import *
from sys import *
from decimal import *

def gcd(a,b):
    if b:
        return gcd(b,a%b)
    return a

kek={"B":0,"u":0,"l":0,"b":0,"a":0,"s":0,"r":0}
ans=0
txt=input()
for i in txt:
    if kek.get(i,-1)!=-1:
        kek[i]+=1
#print(kek)
ans=kek["B"]
for i in "Bulbasaur":
    lol=kek[i]
    if i in "ua":
        lol//=2
    #print(i,lol)
    ans=min(ans,lol)
print(ans)