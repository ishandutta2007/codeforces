s = input()
k = int(input())
if '*' in s:
    newk=''
    bam = len(s)
    cnt = 0
    for t in range(len(s)-1):
        if s[t+1] != '?' and s[t] != '?':
            newk += s[t]
        if s[t] == '*':
            cnt += 1
    if s[-1] == '*':
        cnt += 1
    if s[-1] != '?':
        newk+=s[-1]
    if k + cnt*2 < len(newk):
        print('Impossible')
    elif k + cnt*2 == len(newk):
        zaz=''
        for t in range(len(newk)-1):
            if newk[t] != '*' and newk[t+1]!='*':
                zaz+=newk[t]
        if newk[-1] != '*':
            zaz+=newk[-1]
        print(zaz)
    else:
        newA = ''
        z = k-(len(newk)-2*cnt+1)
        fk = 1
        bi = 0
        for t in range(len(newk)-1):
            if newk[t]!='*' and (newk[t+1] != '*' or fk):
                newA += newk[t]
                if newk[t+1]=='*':
                    newA += newk[t]*(z)
                    fk = 0
        if newk[-1] != '*':
            newA += newk[-1]
        print(newA)
else:
    led = s.count('?')
    if k > len(s)-led or k < len(s)-2*led:
        print('Impossible')
    else:
        zaaz =''
        qqq = len(s)-led-k
        for t in range(len(s)-1):
            if qqq and s[t+1] == '?':
                qqq -= 1
            elif s[t] != '?':
                zaaz += s[t]
        if s[-1] != '?':
            zaaz += s[-1]
        print(zaaz)