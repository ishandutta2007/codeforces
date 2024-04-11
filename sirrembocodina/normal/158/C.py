input = raw_input
n = int(input())
p = [""]
for i in range(n):
	st = str(input()).split()
	if len(st) == 1:
		ans = ""
		for s in p:
			ans += s + "/"
		print(ans)
		continue
	if st[1] == "/":
		p = [""]
		continue	
	if st[1][0] == '/':
		st = st[1].split('/')
		p = []
		for s in st:
			if s == "..":
				p.pop()
			else:
				p.append(s)	
		continue
	st = st[1].split('/')
	for s in st:
		if s == "..":
			p.pop()
		else:
			p.append(s)