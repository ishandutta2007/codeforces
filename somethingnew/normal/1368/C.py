def solve():
    k = int(input())
    ans = [(0, 0)]
    for i in range(1, k + 2):
        ans.append((i-1,i))
        ans.append((i, i-1))
        ans.append((i, i))
    print(len(ans))
    for i in ans:
        print(*i)
for i in range(1):
    solve()