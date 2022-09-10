ran = 20001

def solve():
	a, b, c = [int(x) for x in input().split()]
	ans = int(1e9)


	for B, divsB in zip(range(1, ran), [divs[x] for x in range(1, ran)]):
		curr = int(abs(B-b))
		ile = c//B

		if int(abs(ile*B-c)) <= int(abs((ile+1)*B-c)):
			curr += int(abs(ile*B-c))
			C = ile*B
		else:
			curr += int(abs((ile+1)*B-c))
			C = (ile+1)*B

		ansA = int(1e9)

		for d in divsB:
			if int(abs(d-a)) < ansA:
				ansA = int(abs(d-a))
				A = d

		curr += ansA

		if curr < ans:
			ans = curr
			ra = A
			rb = B
			rc = C

	print(ans)
	print(ra, rb, rc)


divs = [[] for x in range (0, ran)]

for a in range (1, ran):
	for b in range(a, ran, a):
		divs[b].append(a)

t = int(input())

for _ in range(t):
	solve()