N=input()
P=[]
Q=[]
for i in range(N):
	x,y=raw_input().split(' ')
	if (int(x)<0):
		P.append([int(x),int(y)])
	else:
		Q.append([int(x),int(y)])
P.sort()
P.reverse()
Q.sort()
ans=0
if (len(P)==len(Q)):
	for i in P: ans+=i[1];
	for i in Q: ans+=i[1];
else:
	if (len(P)<len(Q)):
		for i in P: ans+=i[1];
		for ic in range(len(P)+1): ans+=Q[ic][1];
	else:
		for ic in range(len(Q)+1): ans+=P[ic][1];
		for i in Q: ans+=i[1];
print ans