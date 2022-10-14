n = int(input())
s = input()
ca = 0
cg = 0
cc = 0
ct = 0
ques = 0
for i in s:
    if i == 'A':
        ca += 1
    elif i == 'G':
        cg += 1
    elif i == 'C':
        cc += 1
    elif i == 'T':
        ct += 1
    else:
        ques += 1
if len(s) % 4 == 0:
    x = len(s) // 4
    if max(ca, cg, cc, ct) <= x:
        t = ''
        for i in s:
            if i != '?':
                t += i
            else:
                if ca < x:
                    ca += 1
                    t += 'A'
                elif cc < x:
                    cc += 1
                    t += 'C'
                elif cg < x:
                    cg += 1
                    t += 'G'
                else:
                    ct += 1
                    t += 'T'
        print(t)
    else:
        print('===')
else:
    print('===')