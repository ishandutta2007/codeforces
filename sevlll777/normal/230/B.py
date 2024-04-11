resheto = [True] * (10 ** 6 + 1)
sus = set()
for p in range(2, 10 ** 3 + 1):
    if resheto[p]:
        for d in range(2 * p, 10 ** 6 + 1, p):
            resheto[d] = False
for i in range(2, 10 ** 6 + 1):
    if resheto[i]:
        sus.add(i ** 2)
input()
for i in list(map(int, input().split())):
    if i in sus:
        print('YES')
    else:
        print('NO')