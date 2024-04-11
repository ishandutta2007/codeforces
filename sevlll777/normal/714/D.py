def ask(x1, y1, x2, y2):
    global ans
    print('?', x1, y1, x2, y2)
    ans = int(input())


def xs1():
    x1, y1 = 1, 1
    x2, y2 = -1, n
    l = 0
    r = n
    while r - l > 1:
        m = (l + r) // 2
        ask(x1, y1, m, y2)
        if ans == 0:
            l = m
        else:
            r = m
    return l + 1


def xs2():
    x1, y1 = 1, 1
    x2, y2 = -1, n
    l = 0
    r = n
    while r - l > 1:
        m = (l + r) // 2
        ask(x1, y1, m, y2)
        if ans <= 1:
            l = m
        else:
            r = m
    return l + 1


def xf1():
    x1, y1 = -1, 1
    x2, y2 = n, n
    l = 1
    r = n + 1
    while r - l > 1:
        m = (l + r) // 2
        ask(m, y1, x2, y2)
        if ans == 0:
            r = m
        else:
            l = m
    return l


def xf2():
    x1, y1 = -1, 1
    x2, y2 = n, n
    l = 1
    r = n + 1
    while r - l > 1:
        m = (l + r) // 2
        ask(m, y1, x2, y2)
        if ans <= 1:
            r = m
        else:
            l = m
    return l


def ys1():
    x1, y1 = 1, 1
    x2, y2 = n, -1
    l = 0
    r = n
    while r - l > 1:
        m = (l + r) // 2
        ask(x1, y1, x2, m)
        if ans == 0:
            l = m
        else:
            r = m
    return l+1


def ys2():
    x1, y1 = 1, 1
    x2, y2 = n, -1
    l = 0
    r = n
    while r - l > 1:
        m = (l + r) // 2
        ask(x1, y1, x2, m)
        if ans <= 1:
            l = m
        else:
            r = m
    return l+1


def yf1():
    x1, y1 = 1, -1
    x2, y2 = n, n
    l = 1
    r = n+1
    while r - l > 1:
        m = (l + r) // 2
        ask(x1, m, x2, y2)
        if ans == 0:
            r = m
        else:
            l = m
    return l


def yf2():
    x1, y1 = 1, -1
    x2, y2 = n, n
    l = 1
    r = n+1
    while r - l > 1:
        m = (l + r) // 2
        ask(x1, m, x2, y2)
        if ans <= 1:
            r = m
        else:
            l = m
    return l


ans = 0
n = int(input())
XF = [xs1(), xs2()]
XS = [xf1(), xf2()]
YF = [ys1(), ys2()]
YS = [yf1(), yf2()]
XS.sort()
XF.sort()
YF.sort()
YS.sort()
for xs11 in XS:
    xs22 = sum(XS) - xs11
    for xf11 in XF:
        xf22 = sum(XF) - xf11
        for ys11 in YS:
            ys22 = sum(YS) - ys11
            for yf11 in YF:
                yf22 = sum(YF) - yf11
                if xf11 >= xs11 and yf11 >= ys11 and xf22 >= xs22 and yf22 >= ys22 and (xs22 > xf11 or ys22 > yf11):
                    kek = 0
                    ask(xs11, ys11, xf11, yf11)
                    kek += ans
                    ask(xs22, ys22, xf22, yf22)
                    kek += ans
                    if kek == 2:
                        print('!', xs11, ys11, xf11, yf11, xs22, ys22, xf22, yf22)
                        exit(0)