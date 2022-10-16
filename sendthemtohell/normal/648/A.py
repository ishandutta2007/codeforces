n,k=(int(z) for z in input().split())
h=[0]*k
for i in range(n):
	s=input()
	for j in range(k):
		if s[j]=='*':
			h[j]+=1
mi=0
ma=0
for i in range(1,k):
	if h[i-1]-h[i]>mi:
		mi=h[i-1]-h[i]
	if h[i]-h[i-1]>ma:
		ma=h[i]-h[i-1]
print(ma,mi)