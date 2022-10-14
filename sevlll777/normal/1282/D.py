from sys import stdout


def f(x):
    if x == 0:
        exit(0)
    stdout.flush()


print('a')
x1 = int(input())
f(x1)
if x1 == 300:
    print('b' * 300)
    exit(0)
lenz = x1 + 1
print('a' * lenz)
x = int(input())
f(x)
ca = lenz - x
patt = ''
c1 = 1
c2 = ca
if ca == 0:
    print('b' * (lenz - 1))
    x = int(input())
    f(x)
else:
    while c2:
        print(patt + 'b' * c1 + 'a' * c2)
        x = int(input())
        f(x)
        if x == lenz - c2 - len(patt) - c1:
            c1 += 1
        else:
            c1 -= 1
            patt += 'b' * c1
            patt += 'a'
            c1 = 1
            c2 -= 1
    print(patt + 'b' * (lenz - len(patt)))
    x = int(input())
    f(x)