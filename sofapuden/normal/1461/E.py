v = list(map(int,input().split()))
v[0]-=v[1]
v[2]-=v[1]
v[1]-=v[1]
d = {}
if(v[4] >= v[5]):
	if(v[0]+v[5] <= v[2]):
		v[0]+=(v[5]-v[4])*v[3]
	else:
		v[0]-=v[4]
		v[0]+=(v[5]-v[4])*(v[3]-1)
	if((v[0] >= v[1] and v[0] <= v[2])): print("Yes")
	else: print("No")
else:
	if(v[2]-v[5] >= v[4]):
		print("Yes")
	else:
		while(True):
			cu = v[0]//v[4]
			if(cu >= v[3]):
				print("Yes")
				exit(0)
			v[3]-=cu
			v[0]-=cu*v[4]
			if v[0] in d:
				print("Yes")
				exit(0)
			d[v[0]] = 1
			if(v[0]+v[5] > v[2]):
				print("No")
				exit(0)
			v[0]+=v[5]