n = int(raw_input())

ans = 0
for i in range(1, 1024) :
	if int(bin(i)[2 :]) <= n :
		ans += 1
print ans