from sys import *

n,m=(int(z) for z in stdin.readline().split())
ans=0
mat=[]
for i in range(n):
    mat.append([int(z) for z in stdin.readline().split()])
    fst=m
    lst=-1
    nu=0
    for j in range(m):
        if mat[-1][j]==1:
            nu+=1
            lst=j
            if not fst-m:
                fst=j
    ans+=lst+1-nu
    ans+=m-fst-nu
    #print(ans)
for i in range(m):
    fst=n
    lst=-1
    nu=0
    for j in range(n):
        if mat[j][i]==1:
            nu+=1
            lst=j
            if not fst-n:
                fst=j
    ans+=lst+1-nu
    ans+=n-fst-nu
    #print(ans,lst,fst,nu)
print(ans)