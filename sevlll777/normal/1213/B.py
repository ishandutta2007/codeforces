for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    m = 10 ** 9
    c = 0
    for i in range(n - 1, -1, -1):
        if A[i] <= m:
            m = A[i]
        else:
            c += 1
    print(c)