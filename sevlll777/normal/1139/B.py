n = int(input())
A = list(map(int, input().split()))
cnt = 0
z = float('inf')
for i in range(n - 1, -1, -1):
    if z > A[i]:
        z = min(z, A[i])
        cnt += z
    else:
        z -= 1
        z = max(0, z)
        cnt += z
print(cnt)