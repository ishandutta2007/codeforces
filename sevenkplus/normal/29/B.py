import math
l,d,v,g,r=map(int,raw_input().split())
L=(d+0.0)/v
R=(d+0.0)/v+(g+r)
for i in xrange(300):
    M=(L+R)/2
    if math.ceil(L/(g+r))!=math.ceil(M/(g+r)):
        R=M
    else:
        L=M
L=(d+0.0)/v
if R-L>r+1e-8:
    R=L
print (R-L)+(l+0.0)/v