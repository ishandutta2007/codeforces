n = int(input())
P = list(map(int, input().split()))
dp = [0] * (n + 2)
dp[1] = 0
M = 10 ** 9 + 7
for i in range(2, n + 2):
    dp[i] = 2 * dp[i - 1] + 2 - dp[P[i - 2]]
    dp[i] %= M
print(dp[-1])