n, w = map(int, input().split())
A = list(map(int, input().split()))
x = 0
p = 10 ** 10
q = 0
for i in A:
    x += i
    p = min(p, x)
    q = max(q, x)
print(max(0, w - q + min(0, p) + 1))