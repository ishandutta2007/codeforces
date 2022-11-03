n, m = map(int, raw_input().split())
n += 4
m += 4
ans = 0
for i in range(5):
	ans += ((n - i) / 5) * ((m - (8 - i) % 5) / 5);
print ans