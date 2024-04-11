def solve():
    s = input()
    n = len(s)
    acnt = 0
    bcnt = 0
    ans = 0
    for i in s:
        if i == "B":
            if acnt:
                acnt -= 1
            else:
                bcnt += 1
        if i == "A":
            acnt += 1
    print(acnt + bcnt % 2)
for i in range(int(input())):
    solve()