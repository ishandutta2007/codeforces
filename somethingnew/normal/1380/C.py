def solve():
    n, x = map(int,input().split())
    lst = list(map(int, input().split()))
    lst2 = [[i, (x + i - 1) // i] for i in lst]
    lst2.sort(reverse=True)
    havepeop = 0
    ans = 0
    for a, i in lst2:
        havepeop += 1
        if havepeop >= i:
            ans += 1
            havepeop -= i
    print(ans)
for i in range(int(input())):
    solve()