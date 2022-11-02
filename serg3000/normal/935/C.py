r,x1,y1,x2,y2 = map(int,input().split())
s = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ** 0.5
#print(s)
s2 = s
if s >= r:
    print(x1,y1,r)
else:
    s += r
    r2 = s / 2
    if s2 == 0:
        print((2 * x1 + r) / 2, y1, r2)
    else:
        ans1 = (((y1 - y2) * s / s2) + 2 * y2) / 2
        ans2 = (((x1 - x2) * s / s2) + 2 * x2) / 2
        print(ans2, ans1, r2)
        #print(r2)