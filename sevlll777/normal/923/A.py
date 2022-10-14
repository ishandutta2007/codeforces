from math import sqrt
N = 10 ** 6 + 1
qis_prime = [True] * (N + 1)
for d in range(2, int(sqrt(N + 1)) + 1):
    for comp in range(2 * d, N + 1, d):
        qis_prime[comp] = False


def is_prime(n):
    return qis_prime[n]


def kryak(x2):
    ans = 0
    for i in range(1, int(x2 ** 0.5) + 1):
        if x2 % i == 0:
            if is_prime(x2 // i):
                return x2 // i
            if is_prime(i):
                ans = max(ans, i)
    return ans


x2 = int(input())
p = kryak(x2)
ans = x2
for x1 in range(x2 - p + 1, x2):
    if not is_prime(x1):
        pp = kryak(x1)
        ans = min(ans, x1 - pp + 1)
    else:
        ans = min(ans, x1)
print(ans)