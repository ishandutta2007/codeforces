a,b,c=map(int,input().split(' '))
b-=1
c-=2
print(min(a,min(b,c))*3+3)