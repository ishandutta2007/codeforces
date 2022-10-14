n = int(input())
A = list(map(int, input().split()))
MS = {}
MD = {}
bil = set()
for i in range(2*n):
    if A[i] in bil:
        MD[A[i]] = i
    else:
        MS[A[i]] = i
    bil.add(A[i])
nowms = 0
nowmd = 0
cnt = 0
for u in range(1, n + 1):
    cnt += abs(MS[u] - nowms)
    cnt += abs(MD[u] - nowmd)
    nowms = MS[u]
    nowmd = MD[u]
print(cnt)