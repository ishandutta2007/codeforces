n, k = map(int, input().split())
D = list(map(int, input().split()))
z = {i: 0 for i in range(k)}
for i in range(n):
    z[D[i] % k] += 1
cnt = z[0] // 2
for q in range(1, k // 2 + k % 2):
    cnt += min(z[q], z[k - q])
if k % 2 == 0:
    cnt += z[k // 2] // 2
print(cnt * 2)