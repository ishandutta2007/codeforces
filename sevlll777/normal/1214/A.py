n = int(input())
d = int(input())
e = int(input())
e *= 5
ans = n
for a in range(n // e + 1):
    ans = min(ans, (n - e * a) % d)
print(ans)