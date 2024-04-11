def solve():
    n = int(input())
    lst = list(input())
    if len(set(lst)) == 1:
        print(n//3 + ((n%3) != 0))
        return 0

    for i in range(n - 1):
        if lst[i] != lst[i + 1]:
            q = i + 1
            break
    lst = [lst[i] for i in range(q, n)] + [lst[i] for i in range(q)]
    rcnt = 0
    lcnt = 0
    ans = 0
    for i in lst:
        if i == "R":
            rcnt += 1
            lcnt = 0
        else:
            lcnt += 1
            rcnt = 0
        if rcnt == 3:
            rcnt = 0
            ans += 1
        if lcnt == 3:
            lcnt = 0
            ans += 1
    print(ans)
for i in range(int(input())):
    solve()