from math import sqrt


def factor(n):
    natural_del = []
    for a in range(1, int(n ** 0.5) + 1):
        if n % a == 0:
            natural_del.append(a)
            natural_del.append(n // a)
    return natural_del


n, k = map(int, input().split())
if n != 1:
    z = factor(n)
    z.append(n)
    fjnt = (1+k*n)
    for d in z:
        if d < k:
            fjnt = min((d + k*(n//d)), fjnt)
    print(fjnt)
else:
    print(k+1)