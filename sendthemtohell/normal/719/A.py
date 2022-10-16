from sys import exit

n=int(input())
d=[int(z) for z in input().split()]
if d[-1]==0:
    print("UP")
    exit(0)
if d[-1]==15:
    print("DOWN")
    exit(0)
if n==1:
    print(-1)
    exit(0)
if d[-1]>d[-2]:
    print("UP")
    exit(0)
print("DOWN")