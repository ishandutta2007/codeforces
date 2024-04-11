from collections import deque
n = int(input())
A = deque(list(map(int, input().split())))
d = 0
s = 0
t = 0
while len(A):
    if A[0] > A[-1]:
        mam = A[0]
        A.popleft()
    else:
        mam = A[-1]
        A.pop()
    if t % 2:
        s += mam
    else:
        d += mam
    t += 1
print(d, s)