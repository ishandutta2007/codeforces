n, m = map(int, input().split())
A=list(map(int,input().split()))
if n > m:
    print(0)
else:
    ans = 1
    for i in range(n):
        for j in range(i+1,n):
            ans*=abs(A[i]-A[j])
            ans%=m
    print(ans)