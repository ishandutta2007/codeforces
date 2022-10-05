def solve():
    n = int(input())
    lst = list(map(int,input().split()))
    if len(set(lst)) == 1:
        print(-1)
    else:
        mx = max(lst)
        if lst[0] == mx and lst[1] < mx:
            print(1)
            return 0
        for i in range(1, n):
            if lst[i] == mx and (lst[i-1] < lst[i] or (i != n - 1 and lst[i] > lst[i + 1])):
                print(i + 1)
                return 0
for i in range(int(input())):
    solve()