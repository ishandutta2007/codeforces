from sys import *

n=int(stdin.readline())
mat=[]
if n==1:
    print(1)
    exit(0)
cur=[int(z) for z in stdin.readline().split()]
mat.append(cur[:])
if 0 in cur:
    sui=sum(cur)
    k=2
    cur=[int(z) for z in stdin.readline().split()]
    mat.append(cur[:])
    su=sum(cur)
else:
    su=sum(cur)
    k=1
for i in range(k,n):
    mat.append([int(z) for z in stdin.readline().split()])
    if 0 in mat[-1]:
        sui=sum(mat[-1])
    elif sum(mat[-1])!=su:
        print(-1)
        exit(0)
if su<=sui:
    print(-1)
    exit(0)
k=False
for i in range(n):
    for j in range(n):
        if mat[i][j]==0:
            mat[i][j]=su-sui
            k=True
            break
    if k:
        break
for i in range(n):
    if sum([mat[j][i] for j in range(n)])!=su:
        print(-1)
        exit(0)
if sum([mat[i][i] for i in range(n)]) !=su:
    print(-1)
    exit(0)
if sum([mat[n-i-1][i] for i in range(n)]) !=su:
    print(-1)
    exit(0)  
print(su-sui)