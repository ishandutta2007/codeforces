w = int(input())
s = input()
F = [1] * 18
for i in range(1, 18):
    F[i] = i * F[i - 1]
a = 0
b = 0
c = 0
d = 0
for i in range(w):
    z = int(s[i])
    if z > 8:
        b += 2
    if z > 7:
        a += 3
    if z > 6:
        d += 1
    if z > 5:
        a += 1
        b += 1
    if z > 4:
        c += 1
    if z > 3:
        a += 2
    if z > 2:
        b += 1
    if z > 1:
        a += 1
ans = ''
a -= d * 4
b -= d * 2
c -= d
ans += '7' * d
b -= c
a -= c * 3
ans += '5' * c
a -= b
ans += '3' * b
ans += '2' * a
print(ans)