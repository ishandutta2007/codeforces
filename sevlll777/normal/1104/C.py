s = input()
ha = [i for i in range(1, 17)]
ha = set(ha)
kletk = set()
for h in s:
    if h == '0':
        ss = ha.difference(kletk)
        for u in [1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12]:
            if u in ss and u+4 in ss:
                kletk.add(u)
                kletk.add(u+4)
                q = u%4
                if q == 0:
                    q += 4
                print(1+((u-1)//4), q)
                break
    else:
        ss = ha.difference(kletk)
        for u in ss:
            if u%4 and (u + 1) in ss:
                kletk.add(u)
                kletk.add(u + 1)
                q = u % 4
                if q == 0:
                    q += 4
                print(1 + ((u - 1) // 4), q)
                break
    udal = set()
    for e in ({1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15}, {4, 8, 12, 16}):
        if e.issubset(kletk):
            for elem in e:
                udal.add(elem)
    kletk.difference_update(udal)