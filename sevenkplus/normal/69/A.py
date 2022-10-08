n=input()
xs,ys,zs=0,0,0
for i in xrange(n):
	x,y,z=map(int,raw_input().split())
	xs+=x
	ys+=y
	zs+=z
if xs==0 and ys==0 and zs==0:
	print "YES"
else:
	print "NO"