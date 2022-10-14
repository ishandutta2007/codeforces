n, m = map(int, input().split())
A = list(map(int, input().split()))
mf = 10 ** 10
for i in range(1, n + 1):
    mf = min(mf, A.count(i))
print(mf)