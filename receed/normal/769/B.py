n=int(input())
a=[int(i) for i in input().split()]
if sum(a)<n-1 or a[0]==0:
    print(-1)
else:
    a=[(a[i],i+1) for i in range(n)]
    p=a[0]
    a.pop(0)
    a.sort(reverse=True)
    a.insert(0,p)
    ans=[]
    ck=1
    for i in range(n):
        for j in range(a[i][0]):
            if ck>=n:
                break
            ans.append((a[i][1],a[ck][1]))
            ck+=1
    print(len(ans))
    for i,j in ans:
        print(i,j)