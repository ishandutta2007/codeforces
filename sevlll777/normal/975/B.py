from copy import copy
qaq = 0
A = list(map(int, input().split()))
for z in range(14):
    if A[z] != 0:
        K = copy(A)
        K[z] = 0
        for t in range(len(K)):
            K[t] += A[z] // 14
        for u in range(z+1, z+1+A[z]%14):
            u %= 14
            K[u] += 1
        cnt = 0
        for t in K:
            if t%2 == 0:
                cnt += t
        qaq = max(qaq, cnt)
print(qaq)