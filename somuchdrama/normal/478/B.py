n, m = map(int, input().split())
kmin = ((m - n % m)*(n//m)*(n//m - 1))//2 + ((n%m) * (n//m+1) * (n//m))//2
kmax = ((n-m+1)*(n-m))//2
print(int(kmin), int(kmax))