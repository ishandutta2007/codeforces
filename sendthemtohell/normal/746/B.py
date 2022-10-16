n=int(input())
s=input()
p1=(n-1)//2+1
p2=(n-1)//2-1
dirr=1
if n%2:
    dir=-1
ans=['']*n
ans[(n-1)//2]=s[0]
for i in range(1,n):
    if dirr>0:
       dirr=-1
       ans[p1]=s[i]
       p1+=1
    else:
        dirr=1
        ans[p2]=s[i]
        p2-=1
if n%2:
    for i in range(n//2):
        ans[i],ans[n-i-1]=ans[n-i-1],ans[i]
print(''.join(ans))