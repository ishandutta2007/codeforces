from math import sqrt

t = int(input())

def ispsq(n):
    s = int(sqrt(n))
    return int(s*s) == n

def solve(n):
    if n % 2 == 1:
        return False
    return ispsq(n//2) or (n % 4 == 0 and ispsq(n//4))

for tc in range(t):
    n = int(input())
    if solve(n):
        print("YES")
    else:
        print("NO")