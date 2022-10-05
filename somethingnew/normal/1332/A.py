for krya in range(int(input())):
    a,b,c,d = map(int, input().split())
    x,y,x1,y1,x2,y2 = map(int,input().split())
    tr = True
    if x1 == x2:
        if b != 0 or a != 0:
            print('NO')
            tr = False
    if tr and y1 == y2:
        if d != 0 or c != 0:
            print('NO')
            tr = False
    if tr:
        xper = b - a
        yper = d - c
        if x1 <= x + xper <= x2 and y1 <= y + yper <= y2:
            print('YES')
        else:
            print('NO')