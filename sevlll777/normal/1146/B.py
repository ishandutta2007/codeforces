s = input()
t = ''
for i in s:
    if i != 'a':
        t += i
if len(t) % 2:
    print(':(')
    exit(0)
q = t[:len(t)//2]
w = t[len(t)//2:]
if q != w:
    print(':(')
    exit(0)
cnt = 0
if len(q) != 0 and s[-len(q):] == q:
    print(s[:-len(q)])
elif len(q) == 0:
    print(s)
else:
    print(':(')