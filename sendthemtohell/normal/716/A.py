n,t=(int(z) for z in input().split())
times=[int(z) for z in input().split()]
cnt=1
for i in range(1,n):
    if times[i]-times[i-1]>t:
        cnt=0
    cnt+=1
print(cnt)