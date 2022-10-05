import math
def solve():
    n = int(input())
    n *= 2
    all = (n-2) * math.pi
    one = math.pi - all/n
    now = one
    ans = 0.5
    for i in range(n//2-1):
        ans += max(math.cos(now), 0)
        now += one
    print(ans*2)
for i in range(int(input())):
    solve()