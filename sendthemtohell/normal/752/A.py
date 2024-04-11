n,m,k=(int(z) for z in input().split())
row=1
while k>2*m:
    k-=2*m
    row+=1
desk=1
while k>2:
    k-=2
    desk+=1
if k-1:
    print(row,desk,"R")
else:
    print(row,desk,"L")