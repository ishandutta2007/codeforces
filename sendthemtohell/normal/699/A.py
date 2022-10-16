n=int(input())

s=input()
p=[int(z) for z in input().split()]
if n==1:
    print(-1)
else:
    mi=float("Inf")
    for i in range(1,n):
        if s[i]=="L" and s[i-1]=="R":
            mi=min(mi,(p[i]-p[i-1])//2)
    if mi==float("Inf"):
        print (-1)
    else:
        print(mi)