from sys import exit
n, m = map(int, input().split())
a = [tuple(input()) for i in range(n)]
whiteline = False
whilecolumne = False
howmany = 0
ar = [[0] * m for i in range(n)]
for x in range(n):
    lastelem = '.'
    shag = 0
    for y in range(m):
        elem = a[x][y]
        if elem == '#':
            if lastelem != elem:
                newnam = howmany + 1
                if x!= 0:
                    if ar[x-1][y] != 0: newnam = ar[x-1][y]
                    elif ar[x][y] != 0: newnam = ar[x][y]
                    else:
                        howmany += 1
                elif ar[x][y] != 0: newnam = ar[x][y]
                else:
                    howmany += 1
                x1 = x + 1
                y1 = y
                ar[x][y] = newnam
                if x1 != n:
                    while y1 != -1 and a[x1][y1] == "#":
                        ar[x1][y1] = newnam
                        y1 -= 1
            else:
                ar[x][y] = ar[x][y-1]
        if elem != lastelem:
            shag += 1
            lastelem = elem
    if shag == 0: whiteline = True
    if shag > 2:
        print(-1)
        exit()
for y in range(m):
    lastelem = '.'
    shag = 0
    for x in range(n):
        elem = a[x][y]
        if elem != lastelem:
            shag += 1
            lastelem = elem
    if shag == 0: whilecolumne = True
    if shag > 2:
        print(-1)
        exit()
if whilecolumne ^ whiteline:
    print(-1)
    exit()
print(howmany)