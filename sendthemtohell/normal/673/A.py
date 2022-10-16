n=int(input())
good=[0]+[int(z) for z in input().split()]+[90]
result=90
for i in range(1,n+2):
    if good[i]-good[i-1]>15:
        result=min(result,good[i-1]+15)
        break
print(result)