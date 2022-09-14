n,h=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
res=0
for i in a:
    if i>h:
        res+=2
    else:
        res+=1
print(res)