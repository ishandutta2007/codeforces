n = int(input())
X = list(map(int, input().split()))
p = min(X)
Q = [0, 0, 0]
for i in X:
    Q[i - p] += 1
z = min(Q[0], Q[2])
rch = Q[1]
v1 = n - 2 * min(Q[0], Q[2])
v2 = Q[0] + Q[2] + Q[1] % 2
if v1 <= v2 or Q[2] == 0 or Q[0] == 0:
    Q[0] -= z
    Q[2] -= z
    Q[1] += 2 * z
    ans = []
    print(v1)
    for _ in range(Q[0]):
        ans.append(p)
    for _ in range(Q[1]):
        ans.append(p + 1)
    for _ in range(Q[2]):
        ans.append(p + 2)
    print(' '.join(list(map(str, ans))))
else:
    Q[0] += rch // 2
    Q[2] += rch // 2
    Q[1] %= 2
    ans = []
    print(v2)
    for _ in range(Q[0]):
        ans.append(p)
    for _ in range(Q[1]):
        ans.append(p + 1)
    for _ in range(Q[2]):
        ans.append(p + 2)
    print(' '.join(list(map(str, ans))))