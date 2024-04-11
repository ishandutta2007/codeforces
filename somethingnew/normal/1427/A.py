def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    if sum(lst) == 0:
        print("NO")
        return 0
    print("YES")
    if sum(lst) > 0:
        lst.sort(reverse=True)
    else:
        lst.sort()
    print(*lst)
for i in range(int(input())):
    solve()