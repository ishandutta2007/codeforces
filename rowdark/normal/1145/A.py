n = int(raw_input())
A = map(int, raw_input().split())
ans = n
while ans != 1:
	st = 0
	flag = False
	while st < n:
		tmpFlag = True
		for i in xrange(ans - 1):
			if A[st + i] > A[st + i + 1]:
				tmpFlag = False
				break
		if tmpFlag:
			flag = True
			break
		else:
			st += ans
	if flag:
		break
	else:
		ans /= 2
print ans