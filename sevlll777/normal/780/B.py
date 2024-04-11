n = int(input())
X = list(map(int, input().split()))
V = list(map(int, input().split()))
l = 0
r = 10 ** 9 + 100
while r - l >= 10 ** -7:
    t = (l + r) / 2
    l2 = 0
    r2 = 10 ** 9
    for i in range(n):
        a, b = X[i] - t * V[i], X[i] + t * V[i]
        r2 = min(b, r2)
        l2 = max(l2, a)
    if l2 <= r2:
        r = t
    else:
        l = t
print(l)