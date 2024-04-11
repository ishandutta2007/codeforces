def solve():
    n = int(input())
    if n == 2:
        print(2)
        print(1, 2)
        return 0
    lst = list(range(1, n + 1))
    ans = []
    ans.append([n-2,n])
    ans.append([n-1,n-1])
    lst.pop()
    lst.pop()
    lst.pop()
    lst.append(n-1)
    while len(lst) > 1:
        a = lst[-1]
        b = lst[-2]
        c = (a + b + 1) // 2
        ans.append([a,b])
        lst.pop()
        lst.pop()
        lst.append(c)
    print(lst[0])
    for i in ans:
        print(*i)
for i in range(int(input())):
    solve()