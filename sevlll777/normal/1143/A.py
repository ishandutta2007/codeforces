n = int(input())
A = list(map(int, input().split()))
A = A[::-1]
print(n - max(A.index(1), A.index(0)))