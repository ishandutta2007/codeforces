def thanos(a, l,r, k):
	if l > r:
		return 0
	else:
			mid = (l+r)//2
			if a[mid] > k:
				return thanos(a, l, mid-1, k)
			else:
				if mid+1 < len(a):
					if a[mid+1] > k:
						return mid+1-l
					else:
						return (mid-l) + thanos(a, mid+1, r, k) + 1
				else:
					return 1
n = int(input())
x = input().split()
for i in range(len(x)):
	x[i] = int(x[i])
x.sort()
q = int(input())
qq = []
while q > 0:
	m = int(input())
	qq.append(thanos(x, 0, len(x)-1, m))
	# print(thanos(x, 0, len(x)-1, m))
	q -= 1
print(*qq, sep='\n')