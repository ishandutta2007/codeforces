n = int(input())
fr = []
sec = []
suf = 0
sus = 0
lal = 0
for i in range(n):
    t = int(input())
    if t < 0:
        sec.append(-t)
        sus -= t
        lal = 'second'
    else:
        fr.append(t)
        suf += t
        lal = 'first'
if suf > sus:
    print('first')
elif sus > suf:
    print('second')
else:
    if sec > fr:
        print('second')
    elif fr != sec:
        print('first')
    else:
        print(lal)