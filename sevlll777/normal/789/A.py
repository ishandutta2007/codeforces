n, k = map(int, input().split())
A = list(map(int, input().split()))
cnt = 0
su = 0
for i in range(n):
    cnt += A[i] // (2 * k)
    A[i] = A[i] % (2 * k)
for i in range(n):
    su += (A[i] + k - 1) // k
print(cnt + (su + 1) // 2)