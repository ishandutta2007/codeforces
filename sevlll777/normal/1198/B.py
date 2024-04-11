from bisect import bisect_right
n = int(input())
A = list(map(int, input().split()))
B = [0] * n
C = []
for i in range(int(input())):
    w = list(map(int, input().split()))
    if w[0] == 1:
        A[w[1] - 1] = w[2]
        B[w[1] - 1] = i
    else:
        C.append((i, w[1]))
sC = [0]
for i in range(len(C) - 1, -1, -1):
    sC.append(max(sC[-1], C[i][1]))
sC = sC[::-1]
for i in range(n):
    A[i] = max(A[i], sC[bisect_right(C, (B[i], 0))])
print(*A)