n,k=[int(i) for i in input().split()]
ar=[0]*101
for i in range(n):
    ar[len(input())]+=1
tru=len(input())
mn=sum(ar[:tru])
mx=sum(ar[:tru+1])-1
print(mn//k*5+mn+1,mx//k*5+mx+1)