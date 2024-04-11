le=[0]*106
n,k=(int(z) for z in input().split())
for i in range(n):
    le[len(input())]+=1
real=len(input())
failed=sum(le[:real+1])-1
best=sum(le[:real])+(sum(le[:real])//k)*5+1
failed+=(failed//k)*5
failed+=1
print(best,failed)