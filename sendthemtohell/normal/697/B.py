from math import *

n=input().split("e")
po=int(n[1])
res=n[0][0]
w=2
while po:
    if w<len(n[0]):
        res+=n[0][w]
    else:
        res+="0"
    po-=1
    w+=1
if w<len(n[0]) and n[0][w:]!="0":
    res+="."
    res+=n[0][w:]
print(res)