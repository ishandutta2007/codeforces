for _ in range(int(input())):
    n = int(input())
    s = list(map(int, list(input())))
    ms = [1] * n
    m = s[-1]
    for i in range(n - 2, -1, -1):
        if m < s[i]:
            ms[i] = 2
        else:
            m = min(m, s[i])
    mans = []
    f = 1
    m2 = -1
    for i in range(n):
        if ms[i] == 2:
            mans.append(2)
            if f:
                m2 = s[i]
                f = 0
        else:
            if m2 < s[i] and m2 != -1:
                mans.append(2)
            else:
                mans.append(1)
    t1 = []
    t2 = []
    for i in range(n):
        if mans[i] == 1:
            t1.append(s[i])
        else:
            t2.append(s[i])
    if t1 == sorted(t1) and t2 == sorted(t2) and (len(t2) == 0 or len(t1) == 0 or t2[0] >= t1[-1]):
        print(''.join(list(map(str, mans))))
    else:
        print('-')