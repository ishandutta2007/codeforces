n,m=(int(z) for z in input().split())
Par=[850]*m
Res=dict()
r=dict()
fail=[0]*m
for i in range(1,m+1):
	r[i]=[]
for i in range(n):
	s=[z for z in input().split()]
	Res[s[0]]=int(s[2])
	if len(r[int(s[1])])<2:
		r[int(s[1])].append(s[0])
		if Par[int(s[1])-1]>int(s[2]):
			Par[int(s[1])-1]=int(s[2])
	elif Par[int(s[1])-1]<int(s[2]):
		if Res[r[int(s[1])][0]]<Res[r[int(s[1])][1]]:
			r[int(s[1])][0]=s[0]
			Par[int(s[1])-1]=min(Res[r[int(s[1])][0]],Res[r[int(s[1])][1]])
			fail[int(s[1])-1]=0
		elif Res[r[int(s[1])][0]]>Res[r[int(s[1])][1]]:
			r[int(s[1])][1]=s[0]
			Par[int(s[1])-1]=min(Res[r[int(s[1])][0]],Res[r[int(s[1])][1]])
			fail[int(s[1])-1]=0
		else:
			fail[int(s[1])-1]=1
			r[int(s[1])][1]=s[0]
	elif Par[int(s[1])-1]==int(s[2]):
		fail[int(s[1])-1]=1
for i in range(1,m+1):
	if fail[i-1]==0:
		print(r[i][0],r[i][1])
	else:
		print('?')