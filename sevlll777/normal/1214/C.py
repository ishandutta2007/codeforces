n = int(input())
s = input()
if 2 * s.count('(') != n:
    print('No')
    exit(0)
b = 0
f = False
kz, kkz = 0, 0
for i in range(n):
    if s[i] == '(':
        b += 1
    else:
        b -= 1
    if b == -1 and not f:
        b = 0
        f = True
    if f:
        if b == 0:
            kz = i
        elif b > 0:
            kkz = i
        else:
            print('No')
            exit(0)
if kkz > kz or not f:
    print('Yes')
else:
    print('No')