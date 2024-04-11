k2,k3,k5,k6=map(int,input().split())
c=min(k2,k5,k6)
k2-=c
d=min(k2,k3)
print(c*256+d*32)