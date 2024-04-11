n,q=map(int,input().split())
sec=[list(map(int,input().split())) for _ in range(q)]
sec=sorted(sec,key=lambda x:(x[0],x[1]))
fence=[0]*(n+1)
for i in sec:
    x,y=i[0],i[1]
    x-=1;y-=1
    fence[x]+=1
    fence[y+1]-=1
for i in range(1,n+1):
    fence[i]+=fence[i-1]
zeroes=[0]*(n);ones=[0]*(n);twos=[0]*(n)
zeroes[0]=1 if fence[0]==0 else 0
ones[0]=1 if fence[0]==1 else 0
twos[0]=1 if fence[0]==2 else 0
for i in range(1,n):
    if fence[i]==0:
        zeroes[i]+=zeroes[i-1]+1
    else:
        zeroes[i]=zeroes[i-1]

for i in range(1,n):
    if fence[i]==1:
        ones[i]+=ones[i-1]+1
    else:
        ones[i]=ones[i-1]

for i in range(1,n):
    if fence[i]==2:
        twos[i]+=twos[i-1]+1
    else:
        twos[i]=twos[i-1]
np=0
for i in range(q):
    x1,y1=sec[i][0],sec[i][1]
    x1-=1;y1-=1
    co1=co2=ct=0
    for j in range(i+1,q):
        x2,y2=sec[j][0],sec[j][1]
        x2-=1;y2-=1
        co1=ones[y1]-(0 if x1==0 else ones[x1-1])
        co2=ones[y2]-(0 if x2==0 else ones[x2-1])
        if x2<=y1:
            ct=twos[min(y1,y2)]-(0 if x2==0 else twos[x2-1])
        else:
            ct=0
        np=max(np,n-(co1+co2+ct+zeroes[-1]))
        #print(i,j,np,co1,co2,ct,zeroes[-1],x2,y1)
print(np)