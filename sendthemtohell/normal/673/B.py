from sys import *

n,m=(int(z) for z in stdin.readline().split())
minofmax=n
maxofmin=1
for i in range(m):
    u,v=(int(z) for z in stdin.readline().split())
    if u>v:
        u,v=v,u
    maxofmin=max(u,maxofmin)
    minofmax=min(v,minofmax)
if maxofmin>minofmax:
    stdout.write("0\n")
else:
   stdout.write(str(minofmax-maxofmin)+"\n")