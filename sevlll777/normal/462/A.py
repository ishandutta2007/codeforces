n = int(input())
A = [[0] * n] + [list(input()) for _ in range(n)] + [[0] * n]
for i in range(len(A)):
    A[i] = [0] + A[i] + [0]
for i in range(1, len(A) - 1):
    for j in range(1, len(A) - 1):
        cnt = 0
        for kek, lol in (i, j + 1), (i, j - 1), (i - 1, j), (i + 1, j):
            if kek != i or lol != j:
                if A[kek][lol] == 'o':
                    cnt += 1
        if cnt % 2:
            print('NO')
            exit(0)
print('YES')