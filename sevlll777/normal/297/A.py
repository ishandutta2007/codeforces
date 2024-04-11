a, b = input(), input()
ca = a.count('1')
cb = b.count('1')
if ca + ca % 2 >= cb:
    print('YES')
else:
    print('NO')