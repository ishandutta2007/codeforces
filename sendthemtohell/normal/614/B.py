from math import *
from sys import *
from decimal import *

n=int(stdin.readline())
k=[z for z in stdin.readline().split()]
zer=0
bad=-1
for i in range(n):
    if k[i] == "0":
        print(0)
        exit(0)
    cnt=0
    for j in k[i]:
        if j != "0":
            cnt += 1
            if j != "1":
                cnt += 2
                break 
    if cnt<2:
        zer += len(k[i])-1
    else:
        bad = i
#print(bad,k[bad])
if bad != -1:
    stdout.write(k[bad]+"0"*zer+"\n")
else:
    stdout.write("1"+"0"*zer+"\n")