def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    if n == len(set(lst)):
        print("NO")
    else:
        print("YES")
for i in range(int(input())):
    solve()