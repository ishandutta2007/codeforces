n, m, k = map(int, input().split())
z = (k + 2 * m - 1) // (2 * m)
q = k % (2 * m)
if q == 0:
    q = 2 * m
q = (q + 1) // 2
w = q % 2
if k % 2:
    w = 'L'
else:
    w = 'R'
print(z, q, w)