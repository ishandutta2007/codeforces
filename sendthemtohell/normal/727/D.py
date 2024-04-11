
from math import *
from sys import *

def conv(s):
	if s=="S" or s=="S\n":
		return 1
	if s=="M" or s=="M\n":
		return 2
	if s=="L" or s=="L\n":
		return 3
	if s=="XL" or s=="XL\n":
		return 4
	if s=="XXL" or s=="XXL\n":
		return 5
	return 6

def uncon(x):
	if x==1:
		return "S"
	if x==2:
		return "M"
	if x==3:
		return "L"
	if x==4:
		return "XL"
	if x==5:
		return "XXL"
	return "XXXL"
	
s=[]
m=[]
l=[]
xl=[]
xxl=[]
sp,mp,lp,xp,xxp=0,0,0,0,0
t=[0]
t+=[int(z) for z in stdin.readline().split()]
n=int(stdin.readline())
ans=[0]*n
#print(t)
for i in range(n):
	e=[conv(z) for z in stdin.readline().split(",")]
	#print(e)
	if len(e)==1:
		ans[i]=e[0]
		t[e[0]]-=1
		if t[e[0]]<0:
			print("NO")
			exit(0)
	else:
		if e[0]==1:
			s.append(i)
		if e[0]==2:
			m.append(i)
		if e[0]==3:
			l.append(i)
		if e[0]==4:
			xl.append(i)
		if e[0]==5:
			xxl.append(i)
while len(s)!=sp and t[1]:
	ans[s[sp]]=1
	sp+=1
	t[1]-=1
while len(s)!=sp and t[2]:
	ans[s[sp]]=2
	sp+=1
	t[2]-=1
if len(s)!=sp:
	print("NO")
	exit(0)
while len(m)!=mp and t[2]:
	ans[m[mp]]=2
	mp+=1
	t[2]-=1
while len(m)!=mp and t[3]:
	ans[m[mp]]=3
	mp+=1
	t[3]-=1
if len(m)!=mp:
	print("NO")
	exit(0)
while len(l)!=lp and t[3]:
	ans[l[lp]]=3
	lp+=1
	t[3]-=1
while len(l)!=lp and t[4]:
	ans[l[lp]]=4
	lp+=1
	t[4]-=1
if len(l)!=lp:
	print("NO")
	exit(0)
while len(xl)!=xp and t[4]:
	ans[xl[xp]]=4
	xp+=1
	t[4]-=1
while len(xl)!=xp and t[5]:
	ans[xl[xp]]=5
	xp+=1
	t[5]-=1
if len(xl)!=xp:
	print("NO")
	exit(0)
while len(xxl)!=xxp and t[5]:
	ans[xxl[xxp]]=5
	xxp+=1
	t[5]-=1
while len(xxl)!=xxp and t[6]:
	ans[xxl[xxp]]=6
	xxp+=1
	t[6]-=1
if len(xxl)!=xxp:
	print("NO")
	exit(0)
res=[uncon(z) for z in ans]
print("YES")
for i in res:
	print(i)