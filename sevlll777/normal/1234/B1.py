from collections import deque
n, k = map(int, input().split())
A = list(map(int, input().split()))
B = deque()
B.append(A[0])
for i in range(1, n):
    if A[i] not in B:
        if len(B) == k:
            B.popleft()
        B.append(A[i])
    else:
        pass
print(len(B))
print(*list(B)[::-1])