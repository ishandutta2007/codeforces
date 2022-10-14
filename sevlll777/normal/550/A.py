s = input()
ab = set()
ba = set()
for i in range(len(s) - 1):
    if s[i] + s[i + 1] == 'AB':
        ab.add(i)
    elif s[i] + s[i + 1] == 'BA':
        ba.add(i)
fl = 0
if ab == set() or ba == set():
    print('NO')
    exit(0)
for s1 in min(ab), max(ab):
    for s2 in min(ba), max(ba):
        if abs(s1 - s2) > 1:
            fl = 1


if fl:
    print('YES')
else:
    print('NO')