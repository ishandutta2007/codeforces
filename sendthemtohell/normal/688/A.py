d,n=(int(z) for z in input().split())
mat=[]
for i in range(n):
    mat.append([int(z) for z in input()])
mm=0
cu=0
for i in range(n):
    if sum([mat[i][z] for z in range(d)])==d:
        cu=0
    else:
        cu+=1
        if cu>mm:
            mm=cu
print(mm)