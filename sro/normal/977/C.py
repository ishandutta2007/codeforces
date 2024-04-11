n,k=map(int,input().split(' '))
a=list(map(int,input().split(' ')))
l=1
r=1000000001
while r-l>1:
	m=(l+r)//2
	cnt=0
	for i in range(n):
		if a[i]<=m:
			cnt+=1
	if cnt>k:
		r=m
	else:
		l=m
cntt=0
for i in range(n):
	if a[i]<=l:
		cntt+=1
if cntt==k:
	print(l)
else:
	print(-1)