n = int(input())
visit = set()
A = [['#'] * n] + [list(input()) for _ in range(n)] + [['#'] * n]
for i in range(len(A)):
    A[i] = ['#'] + A[i] + ['#']
for i in range(1, len(A) - 1):
    for j in range(1, len(A) - 1):
        if A[i][j] == '.' and i * 10 ** 5 + j not in visit:
            f = 1
            for kek, lol in (i, j + 1), (i, j - 1), (i - 1, j), (i + 1, j):
                if A[kek][lol] != '.' or kek * 10 ** 5 + lol in visit:
                    f = 0
            if f:
                for kek, lol in (i, j + 1), (i, j - 1), (i - 1, j), (i + 1, j):
                    visit.add(kek * 10 ** 5 + lol)
                    visit.add(i * 10 ** 5 + j)
        elif A[i][j] == '#':
            visit.add(i * 10 ** 5 + j)
if len(visit) == n * n:
    print('YES')
else:
    print('NO')