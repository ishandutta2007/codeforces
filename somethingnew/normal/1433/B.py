def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    while len(lst) > 0 and lst[-1] == 0:
        lst.pop()
    od = False
    ans = 0
    for i in lst:
        if i == 0 and od:
            ans += 1
        if i == 1:
            od = True
    print(ans)
for i in range(int(input())):
    solve()