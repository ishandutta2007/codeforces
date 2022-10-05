for t in range(int(input())):
    a,b = map(int,input().split())
    if a==b==2:
        print('Yes')
    elif a == 1 or b == 1: print('Yes')
    else: print('No')