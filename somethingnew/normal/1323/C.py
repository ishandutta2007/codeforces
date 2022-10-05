def solve():
    n = int(input())
    st = input()
    g = 0
    leftbp = -1
    ans = 0
    pos = 0
    for i in st:
        pos += 1
        if i == "(":
            g += 1
            if g == 0:
                ans += pos - leftbp + 1
        else:
            g -= 1
            if g == -1:
                leftbp = pos
    if g != 0:
        print(-1)
    else:
        print(ans)
for i in range(1): solve()