def solve(n):
    r = n*(n+1)//2
    i = 1
    while i <= n:
        r -= i * 2
        i *= 2
    return r

t = int(input())
for i in range(t):
    print(solve(int(input())))