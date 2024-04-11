for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    s = sum(A)
    print((s + n - 1) // n)