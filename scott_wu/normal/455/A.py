n = input()
arr = sorted(map(int, raw_input().split()))

atot, btot = 0, 0
lval = 0
for i in arr:
    if i == lval:
        btot += i
    else:
        if i - lval == 1:
            atot, btot = max (atot, btot), atot + i
        else:
            atot, btot = max (atot, btot), max (atot, btot) + i
        lval = i

print max (atot, btot)