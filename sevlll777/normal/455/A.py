n = int(input())
A = list(map(int, input().split()))
B = [0] * (10 ** 5 + 1)
for i in A:
    B[i] += 1
dp = [0] * (10 ** 5 + 1)
if B[1] > 0:
    dp[1] = B[1]
dp[2] = max(dp[1], 2 * B[2])
for i in range(3, 10 ** 5 + 1):
    dp[i] = max(dp[i], B[i - 1] * (i - 1) + dp[i - 3], B[i] * i + dp[i - 2], dp[i - 1])
print(dp[-1])