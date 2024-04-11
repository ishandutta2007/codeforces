n = int(input())
P = list(map(int, input().split()))
Q = {}
for i in P:
    for j in P:
        if i + j not in Q:
            Q[i + j] = 0
        Q[i + j] += 1
ans = 1
for i in Q:
    ans = max(ans, Q[i])
print(ans // 2)