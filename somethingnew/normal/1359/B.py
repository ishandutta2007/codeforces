for t in range(int(input())):
    n,m,x,y = map(int,input().split())
    if x * 2 < y:
        y = x * 2
    ans = 0
    for aewa in range(n):
        save = "*"
        for i in list(input()):
            if i == "." and save == ".":
                ans += y
                save = "*"
            elif i == ".":
                save = "."
            elif save == ".":
                ans += x
                save = "*"
        if save == '.':
            ans += x
    print(ans)