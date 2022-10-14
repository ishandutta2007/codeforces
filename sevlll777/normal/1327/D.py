answers = []
for _ in range(int(input())):
    n = int(input())
    P = [0] + list(map(int, input().split()))
    C = [0] + list(map(int, input().split()))
    ccl = []
    used = [0] * (n+1)
    for v in range(1, n + 1):
        if used[v] == 0:
            used[v] = 1
            x = P[v]
            kk = [C[v]]
            while used[x] == 0:
                kk.append(C[x])
                used[x] = 1
                x = P[x]
            ccl.append(kk)
    ans = n
    for i in range(1, n + 1):
        if i == P[i]:
            ans = 1
    for p in ccl:
        g = len(p)
        for h in range(1, int(g**0.5)+1):
            if g % h == 0:
                hh = g // h
                for Q in [h, hh]:
                    can = 0
                    for st in range(Q):
                        color = p[st]
                        cac = 1
                        for z in range(1, g // Q):
                            if p[st + Q * z] != color:
                                cac = 0
                                break
                        if cac == 1:
                            can = 1
                            break
                    if can:
                        ans = min(ans, Q)
    answers.append(ans)
print('\n'.join(list(map(str, answers))))