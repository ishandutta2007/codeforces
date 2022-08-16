lucky = []
LIMIT=10000000000
inp = raw_input().split()
l = int(inp[0])
r = int(inp[1])

def gen(n):
	if n>LIMIT:
		pass
	else:
		lucky.append(n)
		gen(n*10+4)
		gen(n*10+7)
		
gen(0)


lucky.sort()

ans = 0
for i in range(len(lucky)-1):
	lo = max(l,lucky[i]+1)
	hi = min(r,lucky[i+1])
	
	if hi>=lo:
		ans = ans + (hi-lo+1)*lucky[i+1]
print(ans)