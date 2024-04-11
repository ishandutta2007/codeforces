n = int(input())
if n != 1 and n != 2:
    max12l = [0, 0]
    min12r = [10 ** 10, 10 ** 10]
    badcl = dict()
    badcr = dict()
    for u in range(n):
        l, r = map(int, input().split())
        if l > min(max12l):
            max12l[max12l.index(min(max12l))] = l
        if r < max(min12r):
            min12r[min12r.index(max(min12r))] = r
        if r not in badcr:
            badcr[r] = set()
        badcr[r].add(l)
    lol = 0
    kek = 0
    a = min(max12l)
    b = max(max12l)
    c = min(min12r)
    d = max(min12r)
    interes = [0]
    if b in badcr[c]:
        interes.append(d - a)
    if len(badcr[c]) != 1 or b not in badcr[c]:
        interes.append(d - b)
        interes.append(c - a)
    print(max(interes))
elif n == 2:
    l1, r1 = map(int, input().split())
    l12, r2 = map(int, input().split())
    print(max(r1 - l1, r2 - l12))
else:
    print(0)