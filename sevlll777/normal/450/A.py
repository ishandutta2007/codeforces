from collections import deque
n, m = map(int, input().split())
A = list(map(int, input().split()))
for i in range(n):
    A[i] = [A[i], i + 1]
A = deque(A)
while len(A) > 1:
    x = [A[0][0] - m, A[0][1]]
    A.popleft()
    A.append(x)
    if x[0] <= 0:
        A.pop()
print(A[0][1])