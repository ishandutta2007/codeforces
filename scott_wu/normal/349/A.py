n = raw_input().split()

a, b = 0, 0
bad = 0

for i in map (int, raw_input().split()):
    #print i
    if i == 25:
        a += 1
    elif i == 50:
        if a > 0:
            a -= 1
            b += 1
        else:
            bad = 1
    else:
        if b > 0:
            b -= 1
            if a > 0:
                a -= 1
            else:
                bad = 1
        else:
            if a > 2:
                a -= 3
            else:
                bad = 1

#print bad
print ("YES" if bad == 0 else "NO")