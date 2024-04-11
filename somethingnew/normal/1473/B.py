from math import gcd
def solve():
    s1 = input()
    s2 = input()
    k = len(s1) * len(s2) // gcd(len(s1), len(s2))
    if s1 * (k // len(s1)) == s2 * (k // len(s2)):
        print(s1 * (k // len(s1)))
    else:
        print(-1)
for i in range(int(input())):
    solve()