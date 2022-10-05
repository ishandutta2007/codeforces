for t in range(int(input())):
    n,m,k = map(int,input().split())
    num = n // k
    if num >= m:
        print(m)
    else:
        print(num - ((m-num)//(k-1) + ((m-num)%(k-1)!=0)))