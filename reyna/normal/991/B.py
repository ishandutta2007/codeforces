n = int(input())
a = list(map(int, input().split()))
less = 0
res = 0
for change in range(2, 6):
	cnt = 0
	cur_sum = 0
	for i in range(n):
		cur_sum += a[i]
	for i in range(n):
		if a[i] == change:
			cnt += 1
	least_want = int(4.5 * n + 0.9)
	if least_want <= cur_sum:
		print(res)
		break
	need = int((least_want - cur_sum + (5 - change) - 1) / (5 - change))
	if need <= cnt:
		print(need + res)
		break
	for i in range(n):
		if a[i] == change:
			a[i] = 5
	res += cnt