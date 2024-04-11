from copy import *
def finds(r):
	for i in range(len(r)):
		for j in range(len(r[0])):
			if r[i][j]=='S':
				return i,j

n,m=(int(z) for z in input().split())
r=[]
for i in range(n):
	s=input()
	r.append(s)
x,y=finds(r)
k=1
q,w=x,y
e,t=x,y
while k!=0:
	if q!=n-1 and e!=q+1 and r[q+1][w]=='*':
		print('D',end='')
		q,w,e,t=q+1,w,q,w
	elif q!=0 and e!=q-1 and r[q-1][w]=='*':
		print('U',end='')
		q,w,e,t=q-1,w,q,w
	elif w!=0 and t!=w-1 and r[q][w-1]=='*':
		print('L',end='')
		q,w,e,t=q,w-1,q,w
	elif w!=m-1 and t!=w+1 and r[q][w+1]=='*':
		print('R',end='')
		q,w,e,t=q,w+1,q,w
	else:
		k=0
if q>x:
	print('U')
if q<x:
	print('D')
if w>y:
	print('L')
if w<y:
	print('R')