n=input()
k=1
t=1
while True:
	n-=t
	if n<=0:
		if k==1:
			print "Sheldon"
		elif k==2:
			print "Leonard"
		elif k==3:
			print "Penny"
		elif k==4:
			print "Rajesh"
		elif k==5:
			print "Howard"
		break
	k+=1
	if k==6:
		k=1
		t*=2