n=int(input())
s=list(input())
l,r=0,0
for i in s:
	if i=='(':
		l+=1
	if i==')':
		r+=1
wl=n//2-l
for i in range(n):
	if s[i]=='?':
		if wl:
			s[i]='('
			wl-=1
		else:
			s[i]=')'
c=0
for i in range(n):
	if s[i]=='(':
		c+=1
	else:
		c-=1
	if c<=0 and i<n-1:
		c=-1
		break
if c!=0:
	print(":(")
else:
	print("".join(s))