for _ in range(int(input())):
    n, a, b = map(int, input().split())
    s = input()
    if '1' not in s:
        print((n + 1) * b + a * n)
    else:
        cg = 0
        for i in range(len(s) - 1):
            if s[i] == '1' and s[i - 1] == '0':
                cg += 1
            if s[i] == '1':
                cg += 1
        ans = (n + 1) * b + n * a + cg * b
        c = 0
        D = []
        F = 1
        for i in s:
            if i == '0':
                c += 1
            elif F:
                ans += max(0, a)
                c = 0
                F = 0
            else:
                ans += max(0, min(2 * a, (c - 1) * b))
                c = 0
        ans += max(0, a)
        print(ans)