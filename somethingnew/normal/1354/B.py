def solve():
    lst = list(map(int, input()))
    n = len(lst)
    cou = 0
    nl = []
    le = lst[0]
    for i in lst:
        if i == le:
            cou += 1
        else:
            nl.append([le, cou])
            le = i
            cou = 1
    nl.append([le, cou])
    ans = 0
    for i in range(len(nl) - 2):
        setik = set([nl[i][0],nl[i+1][0],nl[i+2][0]])
        if len(setik) == 3:
            if ans == 0: ans = 1+nl[i+1][1]+1
            ans = min(ans, 1+nl[i+1][1]+1)
    print(ans)
for i in range(int(input())):
    solve()