A=int(raw_input())
a=A
x=0
while a%12==0:
    a/=12
    x+=1
b=[0]*2000
b[0]=2
b[1]=13
for i1 in xrange(1000):
    i=i1+2
    b[i]=b[i-1]*13-b[i-2]*12
y=0
while b[y]<a:
    y+=1
if b[y]!=a:
    print "NO"
else:
    z=x*2+y
    c=[0]*2000
    l=0
    for i in xrange(z/2+1):
        if i!=x:
            c[l]=b[z-i*2]*12**i
            l+=1
    print "YES"
    print "1"
    print z+1
    print l
    for i in xrange(l):
        print c[l-i-1]