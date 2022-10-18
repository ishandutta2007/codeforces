n=int(input())
St=[]
Set=set()
for i in range(n):
	s=input()
	St.append(s)
	Set.add(s)
i=n
while i>0:
	P=St.pop()
	if P in Set:
		Set.remove(P)
		print(P)
	i-=1