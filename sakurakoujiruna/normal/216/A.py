a = [int(x) for x in raw_input().split()]
s = sum(a) - 2
ans = s * (s + 1) / 2
for x in a :
	ans -= x * (x - 1) / 2

print ans