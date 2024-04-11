from math import gcd
p= int(input())-1
ans=0
for j in range(1,p+1):
    if gcd(j,p)==1:
        ans+=1
print(ans)