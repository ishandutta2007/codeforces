k = int(input())
if k % 2 == 0:
    print('NO')
else:
    print('YES')
    reb = [[1, 2]]
    for v in range(3, k + 2):
        reb.append([1, v])
        reb.append([v, k + 2 * v - 4])
        reb.append([v, k + 2 * v - 3])
        reb.append([k + 2 * v - 4, k + 2 * v - 3])
        for u in range(v + 1, k + 2):
            if v + u != k + 4:
                reb.append([v, u])
            reb.append([k + 2 * v - 4, k + 2 * u - 4])
            reb.append([k + 2 * v - 3, k + 2 * u - 3])
    for v in range(3 * k, 4 * k - 1):
        reb.append([2, v])
        reb.append([v, 2 * v - 2 * k - 1])
        reb.append([v, 2 * v - 2 * k])
        reb.append([2 * v - 2 * k, 2 * v - 2 * k - 1])
        for u in range(v + 1, 4 * k - 1):
            if v + u != 7 * k - 2:
                reb.append([v, u])
            reb.append([2 * v - 2 * k, 2 * u - 2 * k])
            reb.append([2 * v - 2 * k - 1, 2 * u - 2 * k - 1])
    print(2 * (3 * k - 2), k * (3 * k - 2))
    for a, b in reb:
        print(a, b)