import sys
a,b,n=map(int,raw_input().split())
for x in xrange(-1000,1001):
    if a*pow(x,n)==b:
        print x
        sys.exit()
print "No solution"