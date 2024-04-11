import sys
sys.setrecursionlimit(1024 * 1024)

def legal(l, r, n, s) :
	return l * n <= s and r * n >= s

def solve(l, r, n, s) :
	if n == 0 :
		return []
	while r + l * (n - 1) > s :
		r -= 1
	return solve(l, r, n - 1, s - r) + [r]

n, k, l, r, sall, sk = [int(x) for x in raw_input().split()]
for i in range(l, r + 1) :
	if legal(l, i, n - k, sall - sk) and legal(i, r, k, sk) :
		ans = solve(l, i, n - k, sall - sk) + solve(i, r, k, sk)
		print ' '.join([str(x) for x in ans])
		break