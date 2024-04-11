ls="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
s,cnt,a1,a2=[],0,[],[]
for i in range(6):
	s.append(list(input()))

def add(c,i):
	global cnt
	cnt+=1
	a1.append(c)
	a2.append(i)

def right(i):
	add('R',i+1)
	tmp=s[i][5]
	for j in range(5,0,-1):
		s[i][j]=s[i][j-1]
	s[i][0]=tmp

def left(i):
	add('L',i+1)
	tmp=s[i][0]
	for j in range(5):
		s[i][j]=s[i][j+1]
	s[i][5]=tmp

def up(j):
	add('U',j+1)
	tmp=s[0][j]
	for i in range(5):
		s[i][j]=s[i+1][j]
	s[5][j]=tmp

def down(j):
	add('D',j+1)
	tmp=s[5][j]
	for i in range(5,0,-1):
		s[i][j]=s[i-1][j]
	s[0][j]=tmp

def chg(i1,j1,i2,j2):
	if i1==i2:
		right(i1);up(j1);right(i1);down(j1)
		right(i1);up(j1);right(i1);down(j1)
		right(i1);up(j1);right(i1);right(i1);down(j1)
	else:
		down(j1);left(i1);down(j1);right(i1)
		down(j1);left(i1);down(j1);right(i1)
		down(j1);left(i1);down(j1);down(j1);right(i1)

for i in range(6):
	for j in range(6):
		toch=ls[i*6+j]
		for ni in range(6):
			for nj in range(6):
				if s[ni][nj]==toch:
					ii,jj=ni,nj
					while jj>j:
						chg(ii,jj-1,ii,jj)
						jj-=1
					while jj<j:
						chg(ii,jj,ii,jj+1)
						jj+=1
					while ii>i:
						chg(ii-1,jj,ii,jj)
						ii-=1
print(cnt)
for i in range(cnt):
	print(a1[i]+str(a2[i]))