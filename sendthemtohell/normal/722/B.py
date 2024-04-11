from sys import *

n=int(input())
p=[int(z) for z in input().split()]
glas=set([ "a", "e", "i", "o", "u", "y"])
for i in range(n):
    s=input()
    nogl=0
    for j in s:
        if j in glas:
            nogl+=1
    if nogl!=p[i]:
        print("NO")
        exit(0)
print("YES")