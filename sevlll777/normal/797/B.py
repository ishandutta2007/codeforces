n = int(input())
A = list(map(int, input().split()))
sumpos = 0
maxoddneg = 100000000
minoddpos = 100000000
for i in A:
    if i > 0:
        sumpos += i
        if i % 2:
            minoddpos = min(minoddpos, i)
    else:
        if i % 2:
            maxoddneg = min(-i, maxoddneg)
if sumpos % 2:
    print(sumpos)
else:
    print(sumpos - min(minoddpos, maxoddneg))