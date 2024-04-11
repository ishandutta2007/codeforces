n=int(input())
a=[0]*n
b=[0]*n
r=[-1]*n
k=0
p=0
for i in range(n):
    x,y=map(int,input().split())
    a[i]=x
    b[i]=y
c=0
for i in range(n):
    if a[i]!=b[i]:
        c=-1
if c==-1:
    print('rated')
else:
    for i in range(n-1):
        if a[i]<a[i+1]:
            c=-2
                    
    if c==-2:
        print('unrated')
        
    else:
        print('maybe')