n = int(input())
a = [int(i) for i in input().split()]
a.sort()
if a[n] == a[n - 1]:
	print('NO')
else:
	print('YES')