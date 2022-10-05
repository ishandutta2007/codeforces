def solve():
    n = int(input())
    lst = list(map(int, input().split()))
    k = lst[0]
    bn = 0
    for i in range(1, n):
        if bn:
            if lst[i] > bn:
                bn = lst[i]
                if k < bn:
                    bn = 0
        else:
            bn = lst[i]
            if k < bn:
                bn = 0
    if bn and k > bn:
        print("NO")
    else:
        print("YES")
for i in range(int(input())):
    solve()