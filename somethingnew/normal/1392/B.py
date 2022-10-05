def solve():
    n,m = map(int,input().split())
    lst = list(map(int,input().split()))
    m %= 2
    for i in range(m + 2):
        k = max(lst)
        lst = [k - i for i in lst]
    print(*lst)
for i in range(int(input())):
    solve()