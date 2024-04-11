import sys
def R(n, k):
    return (n // k) * (k - 1) + (max(n % k - 1, 0)) - k + 1
def solve():
    n = int(input())

    #  k, : R(n) = (n // k) * (k - 1) + (max(n % k - 1, 0))
    gk = 2
    for k in range(3, n):
        if R(n, gk) < R(n, k):
            gk = k
    #   kx,  x ,  ,     n
    anst = [0 if ((1+ i) % gk == 0 or i == n - 1) else 1 for i in range(n)]
    p = 1
    rest = []
    while True:
        if rest:
            if p not in rest: print(len(rest)+1, *rest, p)
            else: print(len(rest), *rest)
        else:
            print(1, p)
        sys.stdout.flush
        k = int(input())
        if k == -1:
            print(0/0)
        rest = []
        for i in range(gk):
            if anst[(k - 1 + i) % n]:
                rest.append((k - 1 + i) % n + 1)
        p += 1
        while p < n + 1 and not anst[p - 1]: p += 1
        if p > n:
            print(0)
            exit()
for i in range(1):
    solve()