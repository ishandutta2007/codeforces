n=int(input())
mat=[]
for i in range(n):
    mat.append(input())
k=False
for i in range(n):
    if "OO" in mat[i]:
        if mat[i][:2]=="OO":
            mat[i]="++"+mat[i][2:]
        else:
            mat[i]=mat[i][:3]+"++"
        k=True
        break
if not k:
    print("NO")
else:
    print("YES")
    for i in mat:
        print(i)