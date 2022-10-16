from math import *
from sys import *

def calc(f):
  return int((1+sqrt(8*f+1))//2)

a,b,c,d=(int(z) for z in input().split())
if a==d==0 and b==1 and c==0:
  print("01")
  exit(0)
if a==d==0 and b==0 and c==1:
  print("10")
  exit(0)
if a==d==0:
  if b+c!=0:
    print("Impossible")
    exit(0)
  print(0)
  exit(0)
if a==0:
  if(sqrt(8*d+1)!=int(sqrt(8*d+1))):
    print("Impossible")
    exit(0)
  if b==c==0:
    ans="1"*calc(d)
    print(ans)
  else:
    if b+c!=calc(d):
      print("Impossible")
      exit(0)
    ans=c*"1"+"0"+b*"1"
    print(ans)
  exit(0)
if d==0:
  if(sqrt(8*a+1)!=int(sqrt(8*a+1))):
    print("Impossible")
    exit(0)
  if b==c==0:
    ans="0"*calc(a)
    print(ans)
  else:
    if b+c!=calc(a):
      print("Impossible")
      exit(0)
    ans=b*"0"+"1"+c*"0"
    print(ans)
  exit(0)
if(sqrt(8*d+1)!=int(sqrt(8*d+1))):
  print("Impossible")
  exit(0)
if(sqrt(8*a+1)!=int(sqrt(8*a+1))):
  print("Impossible")
  exit(0)
x=calc(a)
y=calc(d)
if x*y!=b+c:
  print("Impossible")
  exit(0)
ans=""
res=0
while res+x<=c:
  ans+="1"
  y-=1
  res+=x
while res+x!=c:
  ans+="0"
  x-=1
if res!=c:
  ans+="1"
  y-=1
while x:
  x-=1
  ans+="0"
while y:
  y-=1
  ans+="1"
print(ans)