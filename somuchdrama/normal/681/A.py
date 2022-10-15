n = int(input())
a = [input().split() for i in range(n)]
if sum([int(a[i][1]) >= 2400 and int(a[i][2]) > int(a[i][1]) for i in range(n)]) >= 1:
	print("YES")
else:
	print("NO")