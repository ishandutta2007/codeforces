n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
az = 0
bz = 0
cnt = 0
while az < n and bz < m:
    if A[az] <= B[bz]:
        cnt += 1
        az += 1
        bz += 1
    else:
        bz += 1
print(max(0, n - cnt))