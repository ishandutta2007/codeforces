from sys import *

n=int(stdin.readline())
s=stdin.readline()
m1,m2,ans=0,0,0
for i in range(len(s)):
    if i%2 and s[i]=="r":
        m1+=1
    if not (i%2) and s[i]=="b":
        m2+=1
ans=max(m1,m2)
m1,m2=0,0
for i in range(len(s)):
    if i%2 and s[i]=="b":
        m1+=1
    if not (i%2) and s[i]=="r":
        m2+=1
print(min(ans,max(m1,m2)))