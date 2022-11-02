import sys

def main():
	n = int(sys.stdin.read())
	p = 1
	lst = []
	while p - 1 <= n:
		l = p - 1
		d = 4 * l * l - 4 * l + 1 + 8 * n
		if d >= 0:
			lg = 0
			rg = d
			res = 0
			while lg <= rg:
				m = (lg + rg) / 2
				if m * m <= d:
					res = m
					lg = m + 1
				else:
					rg = m - 1
			if res * res == d:
				k = res - 2 * l + 1
				if k > 0 and k % 2 == 0:
					k = k / 2
					if k % 2 != 0 and k * (k - 1) / 2 + k * l == n:
						lst.append(k * p)
				k = 2 * l - 1 - res
				if k > 0 and k % 2 == 0:
					k = k / 2
					if k % 2 != 0 and k * (k - 1) / 2 + k * l == n:
						lst.append(k * p)
		p = p * 2
	if len(lst) == 0:
		print -1
	else:
		lst.sort()
		for i in lst:
			print i

if __name__ == "__main__":
    main()