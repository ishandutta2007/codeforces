for _ in range(int(input())):
    n = int(input())
    s = input()
    cnt = set()
    i = 0
    ok = True
    while i < n:
        if s[i] in cnt:
            ok = False
            break
        cnt.add(s[i])
        while i + 1 < n and s[i] == s[i+1]:
            i += 1
        i += 1
    print('YES' if ok else 'NO')