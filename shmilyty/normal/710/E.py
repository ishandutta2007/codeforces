m,x,y=map(int,input().split())
a1=[]
a2=[]
s=""
mm=m
while mm:
	a1.append(mm*x)
	a2.append((1+mm)*x)
	s=str(mm%2)+s
	mm//=2
a1.append(0)
a2.append(x)
a1.reverse()
a2.reverse()
for i in range(1,len(a1)):
	if s[i-1]=="1":
		a1[i]=min({a1[i],a1[i-1]+x+y,a2[i-1]+x+y})
		a2[i]=min({a2[i],a1[i-1]+x+y,a2[i-1]+y})
	else:
		a1[i]=min({a1[i],a1[i-1]+y,a2[i-1]+x+y})
		a2[i]=min({a2[i],a1[i-1]+x+y,a2[i-1]+x+y})
print(min(a1[len(a1)-1],a2[(len(a1)-1)]+x))