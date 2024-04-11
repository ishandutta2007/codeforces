n, t, k, d = map(int, input().split())
if d+t >= t*((n+k-1)//k):
    print("NO")
else:
    print("YES")