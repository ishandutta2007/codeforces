n, k = map(int, input().split())
A = list(map(int, input().split()))
me = float('inf')
i = 0
for o in range(k):
    kw = A[o]
    if me > n % kw:
        me = n % kw
        i = o
print(1 + i, n // A[i])