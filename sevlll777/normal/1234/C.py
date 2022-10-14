ans = []
for _ in range(int(input())):
    n = int(input())
    s = list(input())
    t = list(input())
    lvl = 0
    X = [s, t]
    f = 1
    for i in range(n):
        if s[i] in '3456' and t[i] in '3456':
            lvl = 1 - lvl
        elif X[lvl][i] in '3456':
            f = 0
            ans.append('NO')
            break
    if f and lvl == 1:
        ans.append('YES')
    elif f:
        ans.append('NO')
print('\n'.join(ans))