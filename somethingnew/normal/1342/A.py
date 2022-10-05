for t in range(int(input())):
    x,y = map(int,input().split())
    a, b = map(int,input().split())
    k =max(x,y) - abs(x-y)
    b=min(b,a*2)
    n=max(x,y)-k
    print(k*b+n*a)