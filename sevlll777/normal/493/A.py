s = input()
tr = input()
h = set()
g = set()
udalh = set()
udalg = set()
n = int(input())
for i in range(n):
    t, hq, m, y = input().split()
    if hq == 'h':
        if m not in udalh:
            if m in h or y == 'r':
                print(s, m, t)
                udalh.add(m)
            else:
                h.add(m)
    else:
        if m not in udalg:
            if m in g or y == 'r':
                print(tr, m, t)
                udalg.add(m)
            else:
                g.add(m)