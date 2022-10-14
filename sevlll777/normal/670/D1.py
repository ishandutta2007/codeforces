n, k = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
l = 0
r = 10 ** 10
while r - l > 1:
    m = (r + l) // 2
    poroshok = 0
    for i in range(n):
        tr = A[i] * m - B[i]
        poroshok += max(tr, 0)
    if poroshok > k:
        r = m
    else:
        l = m
print(l)