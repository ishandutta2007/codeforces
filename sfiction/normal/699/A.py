n = input()
s = raw_input()
a = map(int, raw_input().split())
ans = 1 << 60
for i in range(1, n):
	if s[i - 1] == 'R' and s[i] == 'L':
		ans = min(ans, a[i] - a[i - 1] >> 1)
print ans if ans < (1 << 60) else -1