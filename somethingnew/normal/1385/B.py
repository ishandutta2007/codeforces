def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    ans = [0 for i in range(n)]
    j = 0
    ann =[]
    for i in range(len(lst)):
        if ans[lst[i]-1] == 0:
            ans[lst[i]-1] = 1
            ann.append(lst[i])
    print(*ann)
for i in range(int(input())):
    solve()