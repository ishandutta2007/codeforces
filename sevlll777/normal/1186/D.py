n = int(input())
S = []
W = []
c = 0
for i in range(n):
    x = float(input())
    S.append(int(x))
    if x % 1 == 0:
        W.append(0)
    elif x > 0:
        W.append(1)
    else:
        W.append(-1)
    if x % 1:
        if x >= 0:
            c += x % 1
        else:
            c += x % 1
            c -= 1
c = round(c)
if c == 0:
    pass
elif c < 0:
    for i in range(len(S)):
        if W[i] == -1:
            S[i] -= 1
            c += 1
        if c == 0:
            break
else:
    for i in range(len(S)):
        if W[i] == 1:
            S[i] += 1
            c -= 1
        if c == 0:
            break
print('\n'.join(list(map(str, S))))