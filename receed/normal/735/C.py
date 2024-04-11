n=int(input())
a,b=1,1
ans=0
while b<=n:
    a,b=b,a+b
    ans+=1
print(ans-1)