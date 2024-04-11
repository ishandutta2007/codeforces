n,a,b,c=[int(i) for i in input().split()]
ans=10**11
for i in range(4):
    for j in range(4):
        for k in range(4):
            if (n+i+j*2+k*3)%4==0:
                ans=min(ans,a*i+b*j+c*k)
print(ans)