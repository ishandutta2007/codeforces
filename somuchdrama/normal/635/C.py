def solve1(s, x):
	if x == 0:
		if s % 2 == 0:
			return 1
		else:
			return 0
	else:
		b = (s + x) // 2
		a = s - b
		if a + b == s and a ^ b == x:
			pw = 0
			full = (s == x)
			for i in range(60):
				if x & (1 << i) != 0:
					pw += 1
				if 2 ** i - 1 == s:
					full = True
			ans = 2 ** pw
			if full:
				ans -= 2
			return ans
		else:
			return 0
def solve2(s, x):
	cnt = 0
	for i in range(1, s):
		j = s - i
		if i ^ j == x:
			cnt += 1
	return cnt
# from random import randint
# while True:
# 	s = randint(0, 10**3)
# 	x = randint(0, 10**3)
# 	if solve1(s, x) != solve2(s, x):
# 		print(s, x, solve1(s, x), solve2(s, x))
# 		break
s, x = map(int, input().split())
print(solve1(s, x))