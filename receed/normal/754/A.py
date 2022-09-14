n=int(input())
a=[int(i) for i in input().split()]
if sum(a)!=0:
    print('YES')
    print(1)
    print(1,n)
else:
    for i in range(n):
        if a[i]!=0:
            print('YES')
            print(2)
            print(1,i+1)
            print(i+2,n)
            break
    else:
        print('NO')