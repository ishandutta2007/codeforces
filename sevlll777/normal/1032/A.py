n, k = map(int, input().split())
sp = list(map(int, input().split()))
d = {}
l2 = []
m = 0
for elem in sp:
    if elem in d:
        d[elem] += 1
    else:
        d[elem] = 1
for e in d:
    if d[e] > m:
        m = d[e]
blud_podano = (m - 1) // k + 1
print(blud_podano*len(d)*k-n)