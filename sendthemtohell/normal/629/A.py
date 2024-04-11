from math import *
from sys import *

n=int(input())
mat=[]
for i in range(n):
    cur=input()
    app=[]
    for i in cur:
        if i=="C":
            app.append(1)
        else:
            app.append(0)
    mat.append(app[:])
res=0
for i in range(n):
    q=sum(mat[i])
    qq=sum([mat[j][i] for j in range(n)])
    res+=q*(q-1)//2
    res+=qq*(qq-1)//2
print(res)