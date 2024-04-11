def belyh(x, y, xx, yy):
    ans=(xx-x+1)*(yy-y+1)//2
    if (xx-x+1)*(yy-y+1)%2==1:
        if (x+y)%2==0:
            ans+=1
    return ans


def chern(x, y, xx, yy):
    return (xx-x+1)*(yy-y+1)-belyh(x,y,xx,yy)


for _ in range(int(input())):
    n, m = map(int, input().split())
    x1, y1, x2, y2 = map(int, input().split())
    x3, y3, x4, y4 = map(int, input().split())
    x5, x6, y5, y6 = max(x1, x3), min(x2, x4), max(y1, y3), min(y2, y4)
    shw = belyh(1, 1, n, m) - belyh(x3, y3, x4, y4) + chern(x1, y1, x2, y2)
    if x5 <= x6 and y5 <= y6:
        shw -= chern(x5, y5, x6, y6)
    w = shw
    b = n * m - w
    print(w, b)