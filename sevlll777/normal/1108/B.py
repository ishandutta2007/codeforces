n = int(input())
dels = list(map(int, input().split()))
z = max(dels)
m1 = 0
hek = dict()
fl = 0
for el in dels:
    if z%el != 0:
        m1 = max(m1, el)
    elif el != z:
        if el not in hek:
            hek[el] = 0
        hek[el] += 1
    else:
        fl += 1
if m1:
    print(z, m1)
elif fl == 1:
    m2 = 1
    for t in hek:
        if hek[t] == 2:
            m2 = max(m2, t)
    print(m2, z)
else:
    print(z, z)