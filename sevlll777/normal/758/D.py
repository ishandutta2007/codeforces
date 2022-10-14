n = int(input())
k = input()
dp = [(10 ** 70)] * (len(k) + 1)
dp[0] = 0
for i in range(1, len(k) + 1):
    for j in range(i):
        if int(k[j:i]) < n and (k[j] != '0' or j == i - 1):
            dp[i] = min(dp[i], dp[j] * n + int(k[j:i]))
print(dp[-1])