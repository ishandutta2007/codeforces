for da in range(int(input())):
    a,b,c = map(int, input().split())
    k = [0] * (b+1)
    rt = list(map(int,input().split()))
    now = rt[:c]
    raz = 0
    for i in now:
        if k[i] == 0:
            raz += 1
        k[i] += 1
    min_raz = raz
    sav = 0
    for i in range(c, len(rt)):
        now.append(rt[c])
        k[rt[sav]] -= 1
        if k[rt[sav]] == 0:
            raz -= 1
        k[rt[i]] += 1
        if k[rt[i]] == 1:
            raz += 1
        sav += 1
        if raz < min_raz:
            min_raz = raz
    print(min_raz)