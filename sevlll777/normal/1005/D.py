def solve(s2):
    dp = [0] * (len(s2) + 1)
    for i in range(len(s2)):
        dp[i + 1] = dp[i]
        if i > 0 and int(s2[i] + s2[i - 1]) % 3 == 0:
            dp[i + 1] = max(dp[i + 1], 1 + dp[i - 1])
        if i > 1 and int(s2[i] + s2[i - 1] + s2[i - 2]) % 3 == 0:
            dp[i + 1] = max(dp[i + 1], 1 + dp[i - 2])
    return dp[-1]


s = list(map(int, input()))
ans = 0
s2 = ""
for c in s:
    if c % 3 == 0:
        ans += solve(s2)
        ans += 1
        s2 = ""
    else:
        s2 += str(c % 3)
ans += solve(s2)
print(ans)