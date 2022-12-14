a = []
a.append(input())
a.append(input())
dp = [-200] * 4
dp[1 * (a[0][0] == 'X') + 2 * (a[1][0] == 'X')] = 0
for i in range(1, len(a[0])):
	odp = dp
	dp = [-200] * 4
	state = 1 * (a[0][i] == 'X') + 2 * (a[1][i] == 'X')
	for last_state in range(4):
		dp[state] = max(dp[state], odp[last_state])
		if last_state != 3 and state == 0:
			dp[3] = max(dp[3], odp[last_state] + 1)
		if last_state == 0:
			if ((~state) & 1):
				dp[state + 1] = max(dp[state + 1], odp[last_state] + 1)
			if ((~state) & 2):
				dp[state + 2] = max(dp[state + 2], odp[last_state] + 1)
print(max(max(dp[0], dp[1]), max(dp[2], dp[3])))