def mult(s, t):
    f1, l1, cntf1, cntl1, beaut1, n1 = s
    f2, l2, cntf2, cntl2, beaut2, n2, p = t
    f3, l3, cntf3, cntl3, beaut3, n3 = 0, 0, 0, 0, beaut1, 0
    f3 = f1
    l3 = l1
    n3 = n1 * (n2 + 1) + n2
    if cntf1 >= n1 and f1 == f2:
        cntf3 = n1 * (cntf2 + 1) + cntf2
    else:
        cntf3 = cntf1
    if cntl1 == n1 and l1 == l2:
        cntl3 = n1 * (cntl2 + 1) + cntl2
    else:
        cntl3 = cntl1
    if f1 != l1:
        if f1 in p:
            beaut3 = max(beaut3, cntf1 + 1)
        if l1 in p:
            beaut3 = max(beaut3, cntl1 + 1)
    elif cntf1 >= n1:
        beaut3 = max(n1, beaut3)
        ans = 0
        h = 0
        for d in p:
            if d == f1:
                h += 1
                ans = max(ans, h)
            else:
                h = 0
        ans = max(ans, h)
        beaut3 = max(beaut3, n1 * (ans + 1) + ans)
    else:
        if f1 in p:
            beaut3 = max(beaut3, 1 + cntf1 + cntl1)
        else:
            beaut3 = max(beaut3, cntf1, cntl1)
    return [f3, l3, cntf3, cntl3, beaut3, n3]


n = int(input())
p = []
for i in range(n):
    p.append(input())
pp = []
for s in p:
    f = s[0]
    l = s[-1]
    cntf = 0
    cntl = 0
    beaut = 1
    hep = 1
    for i in s:
        if i == f:
            cntf += 1
        else:
            break
    for i in s[::-1]:
        if i == l:
            cntl += 1
        else:
            break
    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            hep += 1
        else:
            beaut = max(beaut, hep)
            hep = 1
    beaut = max(beaut, hep)
    pp.append([f, l, cntf, cntl, beaut, len(s), s])
p = pp[::-1]
lasts = p[0][:-1]
for i in range(1, len(p)):
    lasts = mult(lasts, p[i])
print(lasts[-2])