from math import gcd


def sokrat(p, q):
    if p:
        dj = gcd(p, q)
        p, q = p // dj, q // dj
        if p < 0:
            p, q = abs(p), -q
        return (p, q)
    return (0, 1)


n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
pos_d = {}
cnt = 0
ans = 0
for i in range(n):
    if A[i] != 0:
        x = sokrat(-B[i], A[i])
        if x not in pos_d:
            pos_d[x] = 0
        pos_d[x] += 1
    elif B[i] == 0:
        cnt += 1
for i in pos_d:
    ans = max(ans, pos_d[i])
print(int(min(n, ans + cnt)))