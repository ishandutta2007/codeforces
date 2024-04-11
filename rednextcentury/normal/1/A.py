import math
n,m,a=map(int,input().split())
if a>=1 and a<=(10**9):
    square=a
if m>=1 and m<=(10**9):
    length=m
if n>=1 and n<=(10**9):
    width=n
total=(math.ceil(length/square))*(math.ceil(width/square))
print(total)