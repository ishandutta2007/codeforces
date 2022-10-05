for t in range(int(input())):
    n, m = map(int,input().split())
    print((n * m) // 2 + (n*m)%2)