# -*- coding: utf-8 -*-
dat = "".split('')
d1, d2 = "", "!&|()xyz"
for i in range(int(input())):
	s = dat[eval("0b" + ''.join(list(reversed(input()))))]
	for i in range(8): s = s.replace(d1[i], d2[i])
	print(s)