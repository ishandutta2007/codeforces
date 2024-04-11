def solve():
    s = input()
    mp = 0
    p = 0
    for i in s:
        if i == "L":
            p += 1
        else:
            mp = max(mp, p)
            p = 0
    mp = max(mp, p)
    print(mp + 1)
for i in range(int(input())):
    solve()