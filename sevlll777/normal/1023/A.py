n, m = map(int, input().split())
s = input()
t = input()
c = 10000
t += '!' * c
if s == t[:-c]:
    print('YES')
    exit(0)
if '*' not in s:
    print('NO')
    exit(0)
if len(s) - 1 > len(t) - c:
    print('NO')
    exit(0)
pref = ''
suf = ''
f = 0
for i in s:
    if i == '*':
        f = 1
    elif f == 0:
        pref += i
    else:
        suf += i
if t[:len(pref)] == pref and t[-len(suf)-c:-c] == suf:
    print('YES')
else:
    print('NO')