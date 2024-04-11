n=int(input())
s=set()
for i in range(n):
	p=input()
	if i!=n-1:
		s.add(p)
n-=1
w={}
for i in s:
	w.update([(i,set(i))])
w.update([(p,set(p))])
y=''
while n>0:
	u=0
	for i in s:
		u+=1
		if p[0] in w[i] and p[-1] in w[i]:
			p=i
			s.discard(i)
			break
		elif p[0] in w[i]:
			p=i[:i.find(p[0])]+p
			s.discard(i)
			break
		elif p[-1] in w[i]:
			p+=i[i.find(p[-1])+1:]
			s.discard(i)
			break
		elif i[0] in w[p] and i[-1] in w[p]:
			s.discard(i)
			break
		elif u==n:
			y+=p
			p=i
			s.discard(i)
			break
	w.update([(p,set(p))])
	n-=1
p+=y
print(p)