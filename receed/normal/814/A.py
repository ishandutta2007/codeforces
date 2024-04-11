n, k=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
if len(b) != 1:
    print('Yes')
else:
    a[a.index(0)] = b[0]
    for i in range(len(a)-1):
        if a[i]>a[i+1]:
            print('Yes')
            break
    else:
        print('No')