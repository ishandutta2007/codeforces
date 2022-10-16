n=int(input())
a=[int(z)-1 for z in input().split()]
s=0
for i in a:
    s+=i
    if s%2:
        print(1)
    else:
        print(2)