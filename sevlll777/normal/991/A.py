a, b, c, n = map(int, input().split())
if n+c > a+b and c<=b and c <= a:
    print(n-a-b+c)
else:
    print(-1)