for i in range(int(input())):
    L, v, l, r = map(int, input().split())
    cnt = (l-1)//v + (L-r+r%v)//v
    print(cnt)