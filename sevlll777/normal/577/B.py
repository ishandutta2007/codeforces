n, m = map(int, input().split())
A = list(map(int, input().split()))
r = set()
for i in A:
    i %= m
    rzo = set()
    for el in r:
        rzo.add((el + i) % m)
    for elem in rzo:
        r.add(elem)
    r.add(i)
    if 0 in r:
        print('YES')
        exit(0)
print('NO')