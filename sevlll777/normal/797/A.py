def factor(n):
    potentional_p = 3
    itog_list = []
    while n % 2 == 0:
        n = n // 2
        itog_list.append(2)
    while n - 1:
        if potentional_p > n ** 0.5:
            itog_list.append(n)
            return itog_list
        while n % potentional_p == 0:
            n = n // potentional_p
            itog_list.append(potentional_p)
        potentional_p += 2
    return itog_list


n, k = map(int, input().split())
z = factor(n)
if len(z) < k:
    print(-1)
else:
    cnt = 1
    for i in range(len(z) - k + 1):
        cnt *= z[i]
    for i in range(len(z) - k + 1, len(z)):
        print(z[i], end=' ')
    print(cnt)