def solve():
    lst = list(input())
    n = len(lst)
    r = 0
    s = 0
    p = 0
    for i in lst:
        if i == "R":
            p += 1
        if i == "S":
            r += 1
        if i == "P":
            s += 1
    q = max([r,s,p])
    if r == q:
        print("R" * n)
    elif s == q:
        print("S" * n)
    else:
        print("P" * n)
for i in range(int(input())):
    solve()