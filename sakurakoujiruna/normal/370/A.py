r1, c1, r2, c2 = [int(x) for x in raw_input().split()]
ans = [(r1 != r2) + (c1 != c2),
	(r1 + c1 != r2 + c2) + (r1 - c1 != r2 - c2) - 2 * ((r1 + r2 + c1 + c2) & 1),
	max(abs(r1 - r2), abs(c1 - c2))]
print ' '.join([str(x) for x in ans])