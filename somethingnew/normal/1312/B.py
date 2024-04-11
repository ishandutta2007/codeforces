def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    lst.sort(reverse=True)
    print(*lst)
for i in range(int(input())):
    solve()