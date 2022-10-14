kf = int(input())
s = input()
z = 0
e = 0
r = 0
o = 0
n = 0
for i in s:
    if i == 'z':
        z += 1
    elif i == 'e':
        e += 1
    elif i == 'r':
        r += 1
    elif i == 'o':
        o += 1
    else:
        n += 1
x = min(o, n, e)
o -= x
n -= x
e -= x
print('1 ' * x + '0 ' * min(z, e, r, o))