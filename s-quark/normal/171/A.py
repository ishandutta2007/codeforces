a = raw_input()
i = 0;
while(a[i] != ' '):
	i = i+1
b = a[i+1:len(a)]
a = a[0:i]
c = ""
for i in range(0, len(b)):
	c = b[i] + c
print int(a)+int(c)