n,v=map(int,raw_input().split())
ans=[]
for i in range(0,n):
    c=map(int,raw_input().split())
    tc=1
    for j in range(1,c[0]+1):
        if c[j]<v:
            tc=0;
            break;
    if tc==0:
        ans+=[i];
print len(ans)
for i in range(0,len(ans)):
    print ans[i]+1,