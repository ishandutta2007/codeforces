n=int(input())
s=[int(z) for z in input().split()]
q2=[int(z) for z in input().split()]
q1=s
q3=[int(z) for z in input().split()]
res=0
while q2!=s:
	if q2[0]-q1[0]<0 and q3[1]-q2[1]<0:
		res+=1
	elif q2[0]-q1[0]>0 and q3[1]-q2[1]>0:
		res+=1
	elif q2[1]-q1[1]>0 and q3[0]-q2[0]<0:
		res+=1
	elif q2[1]-q1[1]<0 and q3[0]-q2[0]>0:
		res+=1
	if q3!=s:
		q1,q2,q3=q2,q3,[int(z) for z in input().split()]
	else:
		q2=s
print(res)