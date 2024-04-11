n, k = map(int, input().split())
mass = list(map(int, input().split()))
fol = 0
for t in set(mass):
    if mass.count(t) > k:
        fol = 1
for t in range(n):
    mass[t] = [mass[t], t]
psi = [0]*n
mass.sort()
if len(mass) < k or fol:
    print('NO')
else:
    print('YES')
    for t in range(n):
        psi[mass[t][1]] = t%k+1
    print(' '.join(list(map(str, psi))))