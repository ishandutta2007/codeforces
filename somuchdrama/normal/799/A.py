n, t, k, d = map(int, input().split())
print(("YES", "NO")[(d % t == 0 and (d + t) // t * k >= n) or ((d + t - 1) // t) * k >= n])