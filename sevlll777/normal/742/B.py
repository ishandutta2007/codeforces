n, x = map(int, input().split())
A = list(map(int, input().split()))
B = [0] * (10 ** 6 + 1)
for i in A:
    B[i] += 1
ans = 0
if x:
    for i in range(10 ** 5 + 1):
        ans += B[i] * (B[i ^ x])
    print(ans // 2)
else:
    for i in B:
        ans += i * (i - 1) // 2
    print(ans)