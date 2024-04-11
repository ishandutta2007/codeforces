from math import log
for _ in range(int(input())):
    n = int(input())
    s = []
    x = int(log(n, 3))
    while x >= 0:
        if n >= 2 * 3 ** x:
            n -= 2 * 3 ** x
            s.append(2)
        elif n >= 3 ** x:
            n -= 3 ** x
            s.append(1)
        else:
            s.append(0)
        x -= 1
    s = s[::-1]
    l2 = 2229222
    for i in range(len(s)):
        if s[i] == 2:
            l2 = i
    if l2 != 2229222:
        f = 1
        for i in range(len(s)):
            if i <= l2:
                s[i] = 0
            else:
                if s[i] == 0:
                    s[i] = 1
                    f = 0
                    break
                else:
                    s[i] = 0
        if f:
            s.append(1)
    ans = 0
    for i in range(len(s)):
        ans += 3 ** i * int(s[i])
    print(ans)