n = int(raw_input())
soft = 0
hard = 0
for i in xrange(n):
	if raw_input().split()[1] == "soft":
		soft += 1
	else:
		hard += 1
if soft > hard:
	soft, hard = hard, soft
ans = 1
while True:
	b = ans * ans / 2
	w = ans * ans - b
	if soft <= b and hard <= w:
		break
	ans += 1
print ans