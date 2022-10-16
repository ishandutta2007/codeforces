from math import *

def dist(a,b):
    return min(int(fabs( ord(a)-ord(b) ) ) , int(ord("z")-fabs(ord(a)-ord(b))-ord("a")+1) )

s="a"+input()
ans=0
y=[]
for i in range(1,len(s)):
    ans+=dist(s[i],s[i-1])
    y.append(dist(s[i],s[i-1]))
print(ans)
##print(y)