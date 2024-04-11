from math import sqrt, ceil, log2


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
if n == 1:
    print(1, 0)
    exit(0)
F = factor(n)
ans = 1
ma = 0
mi = 10 ** 9
for i in F:
    ans *= i
    ma = max(ma, F[i])
    mi = min(mi, F[i])
ddd = ma
while ddd > 1:
    if ddd % 2 == 0:
        ddd //= 2
    else:
        break
kek = (ddd == 1)
if ma == mi and kek:
    print(ans, ceil(log2(ma)))
else:
    print(ans, 1 + ceil(log2(ma)))