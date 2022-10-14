n = int(input())
A = list(map(int, input().split()))
A.sort()
ans = sum(A[:n//2]) ** 2 + sum(A[n//2:]) ** 2
print(ans)