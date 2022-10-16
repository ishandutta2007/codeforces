from sys import *

res=0
d=dict()
d['C']=6
d['O']=8
d['T']=4
d['D']=12
d['I']=20
n=int(input())
for i in range(n):
    s=input()
    res+=d[s[0]]
print(res)