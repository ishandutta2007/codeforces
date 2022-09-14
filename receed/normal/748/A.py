from math import ceil
n,m,k=[int(i) for i in input().split()]
a=k%(2*m)
if a==0:
    a=2*m

print(ceil(k/(2*m)),(a+1)//2,'RL'[k%2])