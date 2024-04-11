n = int(input())
cnt = 1
tms = 0
ans = 1
prev = 0
while cnt + ans <= n:
	tms += 1
	cnt += ans
	ans, prev = ans + prev, ans
print(tms)