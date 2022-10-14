s = input()
t = input()
t1 = 0
t2 = 0
for i in range(0, len(s), 2):
    q1, q2 = s[i] + s[i + 1], t[i] + t[i + 1]
    if q1 != q2:
        if q1 == '8<':
            if q2 == '()':
                t2 += 1
            else:
                t1 += 1
        elif q1 == '()':
            if q2 == '[]':
                t2 += 1
            else:
                t1 += 1
        else:
            if q2 == '8<':
                t2 += 1
            else:
                t1 += 1
if t1 > t2:
    print('TEAM 1 WINS')
elif t1 == t2:
    print('TIE')
else:
    print('TEAM 2 WINS')