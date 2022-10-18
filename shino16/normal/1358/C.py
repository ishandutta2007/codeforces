

def sum(n):
	return n * (n+1) // 2

def sqsum(n):
	return (n * (n+1) * (n*2+1) // 6)

def vsum(r1, r2, c):
	res = 0
	res += (sqsum(r2) - sqsum(r1-1))
	res += (sum(r2) - sum(r1-1)) * (c*2-1)
	res += (r2 - r1 + 1) * (c * c - c)
	res //= 2
	res += (1-c) * (r2 - r1 + 1)
	return res

def hsum(r1, r2, c):
	res = 0
	res += (sqsum(r2) - sqsum(r1-1))
	res += (sum(r2) - sum(r1-1)) * (c*2-1)
	res += (r2 - r1 + 1) * (c * c - c)
	res //= 2
	res += r2 - r1 + 1 - (sum(r2) - sum(r1-1))
	return res


t = int(input())

for _ in range(t):
		r1, c1, r2, c2 = map(int, input().split())
		ub = vsum(r1, r2, c1) + hsum(c1+1, c2, r2);
		lb = hsum(c1, c2, r1) + vsum(r1+1, r2, c2);
		print(ub - lb + 1)