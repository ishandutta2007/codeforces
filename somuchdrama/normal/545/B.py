s = input()
t = input()
sa = s.count('0')
sb = s.count('1')
ta = t.count('0')
tb = t.count('1')
n = len(s)
L = abs(sa - ta) + abs(sb - tb)
L /= 2
if L % 2 == 1:
    print("impossible")
else:
    ans = ''
    c = 0
    for i in range(n):
        if s[i] == t[i]:
            ans += s[i]
        else:
            if c == 0:
                ans += s[i]
                c = 1
            else:
                ans += t[i]
                c = 0
    print(ans)