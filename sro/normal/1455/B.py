for t in range(int(input())):
	x = int(input())
	fu = 0
	while fu * (fu + 1) // 2 < x: fu += 1
	if fu * (fu + 1) // 2 == x + 1: fu += 1
	print(fu)