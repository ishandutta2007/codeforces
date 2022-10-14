for iw in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    A.sort(reverse=True)
    print(min(A[1] - 1, n - 2))