n = int(input())
heh = []
ans = 0
LminusR = 0
for i in range(n):
    l, r = map(int, input().split())
    LminusR += l
    LminusR -= r
    heh.append(2 * (r - l))
kok = abs(LminusR)
for e in range(n):
    i = heh[e]
    if abs(LminusR + i) > kok:
        kok = abs(LminusR + i)
        ans = e + 1
print(ans)