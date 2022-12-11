t = int(input())

def solve(n):
    if n % 2050 != 0:
        return -1
    k = n // 2050
    return sum(map(int, [c for c in str(k)]))

for tc in range(t):
    n = int(input())
    print(solve(n))