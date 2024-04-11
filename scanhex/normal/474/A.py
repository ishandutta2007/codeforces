__author__ = 'Alex'
a, b = input().strip(), input().strip()
keyb = 'qwertyuiopasdfghjkl;zxcvbnm,./'
for i in b:
    print(keyb[keyb.index(i) - 1] if a == 'R' else keyb[keyb.index(i) + 1], end='')