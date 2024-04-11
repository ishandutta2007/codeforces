def solve():
    n, k = map(int,input().split())
    lst = list(map(int,input().split()))
    ans = [[0 for i in range(56)] for q in range(n)]
    ans2 = [0 for i in range(56)]
    for i in range(n):
        pos = 0
        while lst[i]:
            ans[i][pos] += lst[i] % k
            ans2[pos] += ans[i][pos]
            lst[i] //= k
            pos += 1
    for i in ans2:
        if i > 1:
            print("NO")
            return 0
    print("YES")
for i in range(int(input())):
    solve()