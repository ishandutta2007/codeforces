n = int(input())
A = [0] + list(map(int, input().split()))
for i in range(1, n + 1):
    A[i] += A[i - 1]
for i in range(int(input())):
    l, r = map(int, input().split())
    print((A[r] - A[l - 1]) // 10)