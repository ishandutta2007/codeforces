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


n, k = map(int, input().split())
C = list(map(int, input().split()))
z = factor(k)
z2 = {}
for i in z:
    z2[i] = 0
for i in C:
    for d in z2:
        if z2[d] < z[d]:
            y = 0
            x = i
            while x % d == 0:
                y += 1
                x //= d
            z2[d] = max(z2[d], y)
for d in z:
    if z[d] > z2[d]:
        print('No')
        exit(0)
print('Yes')