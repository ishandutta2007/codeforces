n, m = map(int, input().split())
A = [input() for _ in range(n)]
if n % 3 == 0:
    k = n // 3
    s1 = set()
    s2 = set()
    s3 = set()
    for i in range(k):
        for j in range(m):
            s1.add(A[i][j])
    for i in range(k, 2 * k):
        for j in range(m):
            s2.add(A[i][j])
    for i in range(2 * k, 3 * k):
        for j in range(m):
            s3.add(A[i][j])
    if len(s1) == len(s2) == len(s3) == 1 and len(s1 | s2 | s3) == 3:
        print('YES')
        exit(0)
B = [['0'] * n for _ in range(m)]
for i in range(n):
    for j in range(m):
        B[j][i] = A[i][j]
A = B
n, m =m ,n
if n % 3 == 0:
    k = n // 3
    s1 = set()
    s2 = set()
    s3 = set()
    for i in range(k):
        for j in range(m):
            s1.add(A[i][j])
    for i in range(k, 2 * k):
        for j in range(m):
            s2.add(A[i][j])
    for i in range(2 * k, 3 * k):
        for j in range(m):
            s3.add(A[i][j])
    if len(s1) == len(s2) == len(s3) == 1 and len(s1 | s2 | s3) == 3:
        print('YES')
        exit(0)
print('NO')