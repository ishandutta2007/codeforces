a, b = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(a)]
B = [list(map(int, input().split())) for _ in range(a)]
for i in range(a):
    A[i] += [0] * (b + a)
    B[i] += [0] * (b + a)
for i in range(a - 1):
    a1 = {}
    b1 = {}
    for j in range(i + 1):
        a1[A[j][i - j]] = a1.get(A[j][i - j], 0) + 1
        b1[B[j][i - j]] = b1.get(B[j][i - j], 0) + 1
    if a1 != b1:
        print('NO')
        exit(0)
for i in range(b):
    a1 = {}
    b1 = {}
    for j in range(a):
        a1[A[j][a + i - j - 1]] = a1.get(A[j][a + i - j - 1], 0) + 1
        b1[B[j][a + i - j - 1]] = b1.get(B[j][a + i - j - 1], 0) + 1
    if a1 != b1:
        print('NO')
        exit(0)
print('YES')