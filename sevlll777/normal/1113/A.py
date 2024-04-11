n, v = map(int, input().split())
if n > v:
    z = n - v
    print(v + max(0, z*(z+1)//2 - 1))
else:
    print(n - 1)