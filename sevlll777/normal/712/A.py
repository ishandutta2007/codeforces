n = int(input())
A = list(map(int, input().split()))
B = []
for i in range(n - 1):
    B.append(A[i] + A[i + 1])
B.append(A[-1])
print(*B)