from math import *
from sys import *

def cmp1(a):
    for i in range(3):
        if s[a-i-1]!=s[a+i]:
            return 1
    return 0

def cmp2(a):
    for i in range(2):
        if s[a-i-1]!=s[a+i]:
            return 1
    return 0


s=input()
if len(s)>0:
    sz=len(s)
    r=set()
    j=1
    while j<len(s) and s[-j-1]==s[-1]:
        j+=1
    for i in range(5,len(s)-6):
        if i<len(s)-j-2 or ((len(s)-i-2)%5 in [0,2,3]):
            r.add(s[i]+s[i+1])
    if sz>10 and s[-4]+s[-3] != s[-2]+s[-1]:
        r.add(s[-6]+s[-5])
    if sz>9:
        r.add(s[-5]+s[-4])
    if sz>8:
        r.add(s[-4]+s[-3])
    if sz>6:
        r.add(s[-2]+s[-1])
    for i in range(5,len(s)-7):
        if i<len(s)-j-3 or ((len(s)-i-3)%5 in [0,2,3]):
            r.add(s[i]+s[i+1]+s[i+2])
    if sz>11 and s[-4]+s[-3] != s[-2]+s[-1]:
        r.add(s[-7]+s[-6]+s[-5])
    if sz>10:
        r.add(s[-6]+s[-5]+s[-4])
    if sz>9:
        r.add(s[-5]+s[-4]+s[-3])
    if sz>7:
        r.add(s[-3]+s[-2]+s[-1])
    ans=[]
    for i in r:
        ans.append(i)

ans.sort()
print(len(ans))
for i in ans:
    print(i)