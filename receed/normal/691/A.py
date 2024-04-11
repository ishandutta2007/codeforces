n=int(input())
a=[int(i) for i in input().split()]
if n==1:
    print('YES') if a==[1] else print('NO')
else:
    print('YES') if a.count(0)==1 else print('NO')