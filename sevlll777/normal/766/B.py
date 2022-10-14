n = int(input())
A = list(map(int, input().split()))
A.sort()
for i in range(n - 2):
    x, y, z = A[i], A[i + 1], A[i + 2]
    if z < x + y:
        print('YES')
        exit(0)
print('NO')