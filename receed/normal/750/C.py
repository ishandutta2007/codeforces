n=int(input())
mx=10**9
mn=-mx
p=0
for i in range(n):
    c,d=[int(i) for i in input().split()]
    if d==1:
        mn=max(mn,1900-p)
    else:
        mx=min(mx,1899-p)
    p+=c
if mx==10**9:
    print('Infinity')
elif mx>=mn:
    print(mx+p)
else:
    print('Impossible')