n=int(input())
c=0
a=['']*n
for i in range (n):
    s=input()
    a[i]=s
for i in range(n):
    for j in range(i):
        if a[i]==a[j]:
            print("YES")
            c=1
            break
    if c==0:
        print("NO")
    c=0