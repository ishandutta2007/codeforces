q = raw_input()
t = q.find(' ')
a = int(q[0:t])
q = q[t+1:len(q)]
ans = 0
for i in range(1, a):
	t = q.find(' ')
	x = int(q[0:t])
	q = q[t+1:len(q)]
	ans = ans+x*i
x = int(q)
ans = ans+x*a
print ans