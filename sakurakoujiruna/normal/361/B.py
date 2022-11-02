n, k = [int(x) for x in raw_input().split()]
k = n - k

if k == 0 :
	print -1
else :
	ans = []
	for i in range(2, k + 1) :
		ans.append(i)
	ans.append(1)
	for i in range(k + 1, n + 1) :
		ans.append(i)
	print ' '.join([str(x) for x in ans])