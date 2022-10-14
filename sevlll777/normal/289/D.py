n, k = map(int, input().split())
m=10**9+7
print(pow(k,k-1,m)*pow(n-k,n-k,m)%m)