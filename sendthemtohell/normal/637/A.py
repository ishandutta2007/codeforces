n=int(input())
s=[int(z) for z in input().split()]
D={}
M=s[0]
Mc=1
for i in s:
	if i in D:
		D[i]+=1
		if i==M:
			Mc+=1
		elif D[i]>Mc:
			M=i
			Mc=D[i]
	else:
		D[i]=1
print(M)