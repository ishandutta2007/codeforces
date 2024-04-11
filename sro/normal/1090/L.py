t,n,a,b,k=map(int,input().split(' '))
if n<k:
	print("0")
else:
	a=min(a,t)
	b=min(b,t)
	fb=n//2
	fa=n-fb
	fc=fa*a+fb*b
	if fa>k or (fa==k and fb==k) or (fa==k and a>=b):
		print(min(t,fc//k))
	elif fa==k:
		print(min(t,min(fc//k,min(a*fa//(k-fb),a*fa))))
	else:
		print(min(t,min(fc//k,min(min(b*fb//(k-fa),a*fa//(k-fb)),min(a*fa,b*fb)))))