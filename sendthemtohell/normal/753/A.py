#
from sys import *
n=int(input())
res=0
i=1
while i*(i+1)<=2*n:
            i+=1
print(i-1)
i=1
while res+i+i+1 <=n:
            stdout.write(str(i)+" ")
            res+=i
            i+=1
print(n-res)