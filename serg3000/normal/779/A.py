n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c=0
d=0
z=0
for j in range(5):
    for i in range(n):
        if a[i]==j+1:
            c+=1
    for i in range(n):
        if b[i]==j+1:
            d+=1
    if (c+d)%2==1:
        z=-2
        break
    else:
        z+=abs(c-d)//2
    d=0
    c=0
print(z//2)