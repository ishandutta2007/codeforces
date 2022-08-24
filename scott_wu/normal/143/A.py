r = [int(s) for s in raw_input().split()]
c = [int(s) for s in raw_input().split()]
d = [int(s) for s in raw_input().split()]

found = False
for i in range (1, 10):
    for j in range (1, 10):
        for k in range (1, 10):
            for l in range (1, 10):
                if found:
                    break
                if i != j and i != k and i != l and j != k and j != l and k != l:
                    if i + j == r[0] and k + l == r[1]:
                        if i + k == c[0] and j + l == c[1]:
                            if i + l == d[0] and j + k == d[1]:
                                found = True
                                print str(i) + " " + str(j)
                                print str(k) + " " + str(l)

if not found:
    print -1