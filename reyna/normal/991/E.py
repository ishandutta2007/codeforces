s = input()
cnt = [0 for i in range(10)]
for c in s:
	cnt[ord(c) - ord('0')] += 1
dp = [0 for i in range(20)]	
dp[0] = 1
comb = [[0 for i in range(40)] for j in range(40)]
for i in range(40):
	for j in range(i + 1):
		if i == j or j == 0:
			comb[i][j] = 1
		else:
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1]

for dig in [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]:
	if cnt[dig] == 0:
		continue
	odp = dp
	dp = [0] * 20
	for lsz in range(20):
		for pick in range(1, cnt[dig] + 1):
			if (lsz + pick < 20):
				m = lsz + (dig != 0) + pick - 1
				r = lsz + (dig != 0) - 1
				ways = 0
				if (m == r):
					ways = 1
				elif (r > m or r < 0 or m < 0):
					ways = 0
				else:
					ways = comb[m][r]
				dp[lsz + pick] += odp[lsz] * ways

res = 0
for i in range(1, 20):
	res += dp[i]
print(res)