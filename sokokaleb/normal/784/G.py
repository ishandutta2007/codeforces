x = input()
y = eval(x)
y = str(y)
now = 0
res = ''
for c in y:
    z = ord(c)
    while now < z:
        now += 1
        res += '+'
    while now > z:
        now -= 1
        res += '-'
    res += '.'

print(res)