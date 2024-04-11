from math import *
from sys import *
from queue import *
from decimal import *

s=input()
ans=Decimal(0)
i=0
numpoint=set(["0","1","2","3","4","5","6","7","8","9","."])
while i<len(s):
    if s[i] in numpoint:
        p=i
        q=100
        while i<len(s) and s[i] in numpoint:
            if(s[i]=="."):
                s=s[:i]+s[i+1:]
                q=0
            else:
            	q+=1
            	i+=1
        if q<=2:
        	ans+=Decimal(int(s[p:i]))/Decimal(100)
        else:
        	ans+=Decimal(int(s[p:i]))
    else:
        i+=1
##print(ans)
if ans==int(ans):
	ans=str(int(ans))
elif ans*10==int(ans*10):
	ans=str(int(ans*10)/10)+"0"
else:
	ans=str(ans)
ans=ans[::-1]
q=0
res=""
for i in ans:
	res+=i
	q+=1
	if i==".":
		q=0
	if q==3:
		q=0
		res+="."
if res[-1]==".":
	res=res[len(res)-2::-1]
else:
	res=res[::-1]
print(res)