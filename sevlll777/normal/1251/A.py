for _ in range(int(input())):
	s = input()
	t = ''
	lc=s[0]
	cnt=1
	for i in range(1,len(s)):
		if s[i]==lc:
			cnt+=1
		else:
			t+=lc*(cnt%2)
			lc=s[i]
			cnt=1
	t+=lc*(cnt%2)
	print(''.join(sorted(list(set(t)))))