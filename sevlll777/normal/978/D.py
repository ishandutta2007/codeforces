from copy import copy
n = int(input())
Az = list(map(int, input().split()))
if len(Az) == 1 or len(Az) == 2:
    print(0)
else:
    cn = float('inf')
    for s1 in [1, 0, -1]:
        for s2 in [-1, 0, 1]:
            A = copy(Az)
            fl = 1
            cnt = 0
            if s1 != 0:
                cnt += 1
            if s2 != 0:
                cnt += 1
            A[0] += s1
            A[1] += s2
            shag = A[1] - A[0]
            for y in range(2, len(A)):
                if A[y] - A[y - 1] == shag + 1:
                    A[y] -= 1
                    cnt += 1
                elif A[y] - A[y - 1] == shag - 1:
                    A[y] += 1
                    cnt += 1
                elif A[y] - A[y - 1] == shag:
                    pass
                else:
                    fl = 0
            if fl:
                cn = min(cn, cnt)
    if cn == float('inf'):
        print(-1)
    else:
        print(cn)