def kk(x, y):
    res = 0
    if ((2 < x) and (x < 5)):
        res = 1
    return res + 10 - y // 2

a = []
for i in range(6):
    s = raw_input()
    a.append(s)
x = -1
y = -1
bst = -1

for i in range(6):
    for j in range(8):
        if (a[i][j] == '.'):
            cur = kk(j, i)
            if (cur > bst) :
                bst = cur
                x = j
                y = i

b = []
s = 'P';

for i in range(6):
    if i == y:
        if x == 0:
            b.append('P' + a[i][1:8])
        elif x == 7:
            b.append(a[i][0:7] + 'P')
        else :
            b.append(a[i][0:x] + 'P' + a[i][(x+1):8])
    else:
        b.append(a[i])

for i in range(6):
    print(b[i])