
T=int(input())
for tt in range(T):
    n=int(input())
    a=list(map(int, input().split()))
    orig=list(a)
    a.sort()
    prefixes=[]
    prefixSum=0
    prefixes.append(prefixSum)
    for i in a:
        prefixSum+=i
        prefixes.append(prefixSum)

    ans=0
    for i in range(n-1):
        if prefixes[i+1]<a[i+1]:
            ans=a[i+1]
    
    count=0
    for i in orig:
        if i>=ans:
            count+=1
    print(count)
    for i in range(n):
        if (orig[i]>=ans):
            print(i+1, end=" ")
    print()