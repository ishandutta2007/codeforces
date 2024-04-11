def solve():
    x1,y1,x2,y2 =map(int,input().split())
    t = 0
    ans = 0
    if x1 != x2:
        ans += abs(x1 -x2)
        t += 1
    if y1 != y2:
        ans += abs(y1-y2)
        t += 1
    print(ans + max(t-1,0) * 2)
for i in range(int(input())):
    solve()