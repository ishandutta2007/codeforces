n,k=[int(i) for i in input().split()]
t=(240-k)//5
i=0
while i+1<=t:
    i+=1
    t-=i
print(min(i,n))