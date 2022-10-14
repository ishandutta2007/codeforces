for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    gg = 1
    for z in range(1, n + 1):
        for x in range(n):
            if A[x] == z:
                r = x
                ggg = gg
                while r >= gg and A[r] < A[r - 1]:
                    A[r - 1], A[r] = A[r], A[r - 1]
                    r -= 1
                    ggg = x +1
                gg = ggg
    print(*A)