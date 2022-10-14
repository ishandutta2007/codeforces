from math import gcd
from math import sqrt


def factor(n):
    potentional_p = 3
    itog_list = {}
    if n % 2 == 0:
        itog_list[2] = 0
    while n % 2 == 0:
        n = n // 2
        itog_list[2] += 1
    while n - 1:
        if potentional_p > sqrt(n):
            if n in itog_list:
                itog_list[n] += 1
            else:
                itog_list[n] = 1
            return itog_list
        while n % potentional_p == 0:
            n = n // potentional_p
            if potentional_p in itog_list:
                itog_list[potentional_p] += 1
            else:
                itog_list[potentional_p] = 1
        potentional_p += 2
    return itog_list


n = int(input())
A = list(map(int, input().split()))
g = 1
if n == 1:
    g = A[0]
else:
    g = gcd(A[0], A[1])
    for i in range(2, n):
        g = gcd(g, A[i])
F = factor(g)
ans = 1
for i in F:
    ans *= (F[i] + 1)
print(ans)