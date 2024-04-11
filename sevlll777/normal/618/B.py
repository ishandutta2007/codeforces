n = int(input())
fl = 0
A = [list(map(int, input().split())) for i in range(n)]
for i in range(n):
    kok = []
    for u in A:
        kok.append(u[i])
    if len(set(kok)) == len(kok):
        print(n - fl, end=' ')
        fl = 1
    else:
        ans = 0
        pri = 122
        for U in set(kok):
            if kok.count(U) > ans:
                ans = kok.count(U)
                pri = U
        print(pri, end=' ')