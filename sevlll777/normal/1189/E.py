n, p, k = map(int, input().split())
A = list(map(int, input().split()))
step4 = {}
for i in A:
    h = (i ** 4) - (k * i)
    h %= p
    if h not in step4:
        step4[h] = 0
    step4[h] += 1
ans = 0
for u in step4:
    ans += (step4[u]) * (step4[u] - 1) // 2
print(ans)