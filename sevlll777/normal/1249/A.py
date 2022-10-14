for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    A.sort()
    ans = 1
    for i in range(n - 1):
        if A[i] + 1 == A[i + 1]:
            ans = 2
            break
    print(ans)