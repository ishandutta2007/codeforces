from collections import deque
n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
B = deque(B)
cnt = 0
for i in range(n):
    if B[0] >= A[i]:
        cnt += 1
        B.popleft()
    if cnt == min(n, m):
        print(cnt)
        exit(0)
print(cnt)