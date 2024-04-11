n, k = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
for i in range(1, n):
    A[i] += A[i - 1]
pos = []
for i in A:
    pos.append(B[0] - i)
pos = set(pos)
cnt = 0
b = set(B)
for p in pos:
    s = set()
    for u in A:
        s.add(u + p)
    if s.intersection(b) == b:
        cnt += 1
print(cnt)