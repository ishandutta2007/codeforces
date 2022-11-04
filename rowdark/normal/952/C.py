def Abs(x):
	return -x if x < 0 else x
n = int(raw_input())
s = map(int, raw_input().split(" "))
flag = True
for i in xrange(n - 1):
	if Abs(s[i] - s[i + 1]) >= 2:
		flag = False
		break
print "YES" if flag else "NO"