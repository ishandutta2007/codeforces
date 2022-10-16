n,a,b=(int(z) for z in input().split())
if b>=0:
	for i in range(b):
		a+=1
	a%=n
if b<0:
	for i in range(-b):
		a-=1
	a%=n
if a==0:
	a=n
print(a)