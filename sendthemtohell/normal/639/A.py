n,k,q=(int(z) for z in input().split())
s=[int(z) for z in input().split()]
t=[]
ans=[]
for i in range(q):
	r=input()
	if r[0]=='2':
		if s[int(r[2:])-1] in t:
			ans+=['YES']
		else:
			ans+=['NO']
	else:
		if len(t)<k:
			t.append(s[int(r[2:])-1])
			t.sort()
			t.reverse()
		else:
			u=0
			while u<=k-1 and t[u]>s[int(r[2:])-1]:
				u+=1
			if u<k:
				for g in range(k-1,u,-1):
					t[g]=t[g-1]
				t[u]=s[int(r[2:])-1]
for h in ans:
	print(h)