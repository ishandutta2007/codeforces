from random import randint
for _ in range(int(input())):
    n, m = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(n)]
    ans = 0
    for _ in range(100):
        for j in range(m):
            x = randint(0, n - 1)
            if x:
                B = []
                for i in range(n):
                    B.append(A[i][j])
                B = B[x:] + B[:x]
                for i in range(n):
                    A[i][j] = B[i]
        c = 0
        for i in range(n):
            c += max(A[i])
        ans = max(ans, c)
    print(ans)