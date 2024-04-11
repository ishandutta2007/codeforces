
from sys import *

n=int(stdin.readline())
dem=[]
rep=[]
dp=0
rp=0
s=stdin.readline()
for i in range(len(s)):
    if s[i]=="D":
        dem.append(i)
    if s[i]=="R":
        rep.append(i)
j=len(rep)+len(dem)
while dp<len(dem) and rp<len(rep):
    r=rep[rp]
    d=dem[dp]
    if r<d:
        rep.append(j)
    else:
        dem.append(j)
    j+=1
    rp+=1
    dp+=1
if len(dem)==dp:
    print("R")
else:
    print("D")