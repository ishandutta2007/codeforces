n = int(input())
A = []
z1, z2, z3, z4, z5, z6, z7 = [10 ** 9] * 7
kop = set()
for _ in range(n):
    c, s = input().split()
    c = int(c)
    s = ''.join(sorted(list(set(s))))
    for _ in s:
        kop.add(_)
    if s == 'A':
        z1 = min(z1, c)
    elif s == 'B':
        z2 = min(z2, c)
    elif s == 'C':
        z3 = min(z3, c)
    elif s == 'AB':
        z4 = min(z4, c)
    elif s == 'AC':
        z5 = min(z5, c)
    elif s == 'BC':
        z6 = min(z6, c)
    elif s == 'ABC':
        z7 = min(z7, c)
if len(kop) == 3:
    print(min(z7, z1 + z2 + z3, z1 + z6, z2 + z5, z3 + z4, z4 + z5, z4 + z6, z5 + z6))
else:
    print(-1)