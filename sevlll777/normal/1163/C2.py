n = int(input())
T = []
P = []
for i in range(n):
    x, y = map(int, input().split())
    T.append([x, y])
for i in range(n):
    for j in range(i + 1, n):
        x1, y1 = T[i]
        x2, y2 = T[j]
        a = y2 - y1
        b = x1 - x2
        c = -(a * x1 + b * y1)
        if a != 0:
            b /= a
            c /= a
            a = 1
        else:
            a = 0
            c /= b
            b = 1
        P.append([a, b, c])
P.sort()
newp = [P[0]]
for i in range(len(P) - 1):
    if P[i] != P[i + 1]:
        newp.append(P[i + 1])
P = newp
sos = dict()
for a, b, c in P:
    if b != 0 and a != 0:
        z = a / b
    elif a == 0:
        z = 'kek'
    else:
        z = 'lol'
    if z not in sos:
        sos[z] = 1
    else:
        sos[z] += 1
sus = 0
sussqua = 0
for i in sos:
    sus += sos[i]
    sussqua += sos[i] ** 2
print((sus ** 2 - sussqua) // 2)