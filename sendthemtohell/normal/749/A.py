n=int(input())
if n%2:
    print(1+(n-3)//2)
    ans=[3]
    n-=3
    while n:
        ans.append(2)
        n-=2
else:
    print(n//2)
    ans=[2]
    n-=2
    while n:
        ans.append(2)
        n-=2
print(' '.join(map(str,ans)))