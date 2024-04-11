s,n=(z for z in input().split())
n=int(n)
if(s.count('0')<n):
    print(len(s)-1)
else:
    cnt=0
    i=1
    while cnt<n:
        if s[-i]=='0':
            cnt+=1
        i+=1
    print(i-1-cnt)