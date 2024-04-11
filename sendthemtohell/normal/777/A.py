n=int(input())
x=int(input())
n%=6
a=[[0,1,1,2,2,0],[1,0,2,1,0,2],[2,2,0,0,1,1]]
print(a[x][n])