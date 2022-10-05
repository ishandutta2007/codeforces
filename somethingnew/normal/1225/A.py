a, b = map(int, input().split())
if a == 9 and b == 1:
    print(99,100)
elif b - a > 1 or a > b:
    print(-1)
elif abs(a-b) == 1:
    print(a,b)
else:
    print(a,'0 ',b,'1',sep='')