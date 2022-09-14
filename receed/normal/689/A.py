n=int(input())
inp=[int(i) for i in input()]
a=[[1,2,3],[1,4,7,0],[7,0,9],[3,6,9,0]]
res='YES'
for i in a:
    for j in i:
        if j in inp:
            break
    else:
        res='NO'
print(res)