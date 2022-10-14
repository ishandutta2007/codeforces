n = int(input())
A = list(map(int, input().split()))
for i in range(n):
    A[i] %= 2
print(min(n - A.count(0), A.count(0)))