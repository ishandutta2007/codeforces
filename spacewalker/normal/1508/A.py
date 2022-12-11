from itertools import product
def mix(tpl, c):
    a, b = tpl
    n = len(a)
    ans = []
    ap, bp = 0, 0
    while True:
        while ap < n and a[ap] != c:
            ans.append(a[ap])
            ap += 1
        while bp < n and b[bp] != c:
            ans.append(b[bp])
            bp += 1
        if ap < n or bp < n:
            ans.append(c)
            ap += 1
            bp += 1
        if ap >= n and bp >= n:
            break
    return ''.join(ans)

def solve():
    n = int(input())
    a, b, c = [input() for i in range(3)]
    return min([mix(*p) for p in product([(a, b), (b, c), (c, a)], "01")], key=len)

t = int(input())
for tc in range(t):
    print(solve())