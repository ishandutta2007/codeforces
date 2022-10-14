for _ in range(int(input())):
    h, n = map(int, input().split())
    P = list(map(int, input().split()))[::-1]
    P.pop()
    ans = 0
    while h > 2 and P:
        w = P.pop()
        if (h - w) == 1:
            if P:
                q = P.pop()
                if (h - q) != 2:
                    ans += 1
                    P.append(q)
            else:
                ans += 1
            h -= 2
        else:
            h = w + 1
            P.append(w)
    print(ans)