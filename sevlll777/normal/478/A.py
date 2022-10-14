s=sum(list(map(int,input().split())))
if s%5 or s==0:
    print(-1)
else:
    print(s//5)