n = int(input())
A = list(map(int, input().split()))
if n == 1:
    print(1)
    print(1)
    exit(0)
print(A.count(1))
A.append(1)
for i in range(1, n + 1):
    if A[i] == 1:
        print(A[i - 1], end=' ')