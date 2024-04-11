from math import sqrt


def factor(n):
    potentional_p = 3
    itog_list = []
    while n % 2 == 0:
        n = n // 2
        itog_list.append(2)
    while n - 1:
        if potentional_p > sqrt(n):
            itog_list.append(n)
            return itog_list
        while n % potentional_p == 0:
            n = n // potentional_p
            itog_list.append(potentional_p)
        potentional_p += 2
    return itog_list


n, m = map(int, input().split())
if m % n != 0:
    print(-1)
    exit(0)
z = m // n
F = factor(z)
if F == []:
    print(0)
    exit(0)
if (len(set(F)) == 2 and 2 in F and 3 in F) or (len(set(F)) == 1 and (2 in F or 3 in F)):\
    print(len(F))
else:
    print(-1)