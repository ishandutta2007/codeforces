n=int(input())
ans=0
for i in range(n):
    if sum([int(z) for z in input().split ()])>1:
        ans+=1
print(ans)