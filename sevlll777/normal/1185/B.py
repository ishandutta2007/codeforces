for e in range(int(input())):
    s, t = input(), input()
    u = 0
    j = 0
    f = 1
    while u < len(s) and j < len(t):
        if s[u] == t[j]:
            u += 1
            j += 1
        else:
            if u and s[u - 1] == t[j]:
                j += 1
            else:
                f = 0
                break
    if f and u == len(s) and (j == len(t) or {s[-1]} == set(t[j:])):
        print('YES')
    else:
        print('NO')