def solve():
    s = input()
    ans = 0
    k = 0
    kp = 0
    t = (s[-1] == "-")
    for i in range(len(s)):
        if s[i] == "-":
            kp -= 1
        else:
            kp += 1
        k = min(k, kp)
    k = -k + 1
    kp = 0
    lkp = 0
    for i in range(len(s)):
        if s[i] == "-":
            kp -= 1
        else:
            kp += 1
        ans += k
        if kp < min(0, lkp):
            k += kp - lkp
            lkp = kp
    print(ans)
for i in range(int(input())):
    solve()