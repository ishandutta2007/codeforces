from math import *

d,h,v,e=(int(z) for z in input().split())
v=v/(acos(-1)*d*d/4)
if v-e<=0:
  print("NO")
else:
  print("YES")
  print(h/(v-e))