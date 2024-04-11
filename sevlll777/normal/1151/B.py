n, m = map(int, input().split())
A = [list(map(int, input().split())) for i in range(n)]
xox = 0
s = 0
F = 0
for i in range(n):
    M = A[i]
    if not F and len(set(M)) != 1:
        s = i
        F = 1
    else:
        xox ^= M[0]
if F:
    ans = [1] * n
    for i in range(m):
        if A[s][i] != xox:
            ans[s] = i + 1
    print('TAK')
    print(' '.join(list(map(str, ans))))
else:
    if xox == 0:
        print('NIE')
    else:
        print('TAK')
        print('1 ' * n)