n,m=[int(i) for i in input().split()]
ans=100000000
for i in range(m):
    k,l=[int(i) for i in input().split()]
    ans=min(ans,l-k+1)
print(ans)
print(' '.join([str(i%ans) for i in range(n)]))