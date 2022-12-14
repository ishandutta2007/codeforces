import math
n = 0
d = 0

def get(x) :
    return x + d / (x + 1)

for i in range(int(input())):
    n, d = map(int, input().split())
    l, r = 0, n
    while l + 2 < r :
        m1 = (l*2 + r) // 3
        m2 = (l + r*2) // 3
        if get(m1) > get(m2) :
            l = m1
        else :
            r = m2
    timer1 = get(l)
    timer2 = get(r)
    timer3 = get((l+r) // 2)
    if min(timer1, timer2, timer3) <= n :
        print("YES")
    else :
        print("NO")