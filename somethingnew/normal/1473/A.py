def solve():
    n, d = map(int, input().split())
    lst = list(map(int, input().split()))
    lst.sort()
    if lst[0] + lst[1] <= d or max(lst) <= d:
        print("YES")
    else:
        print("NO")
for i in range(int(input())):
    solve()