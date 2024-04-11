s = input()
itself = {'A', 'H', 'I', 'M', 'O', 'o', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y'}
d = {'p' : 'q', 'q' : 'p', 'b' : 'd', 'd' : 'b'}
for i in itself:
	d[i] = i
ok = True
for i in range(len(s)):
	ok &= s[i] in d.keys() and s[len(s) - i - 1] == d[s[i]]
print("TAK" if ok else "NIE")