n = int(input())
Q = list(map(int, input().split()))
for i in range(1, n - 1):
    Q[i] += Q[i - 1]
z = min(Q)
p0 = 1 - z
chach = set()
ans= []
for i in range(1, n + 1):
    chach.add(i)
if p0 != 0:
    ans.append(p0)
    for i in Q:
        ans.append(i + p0)
elif p0 == 0:
    ans.append(1)
    for i in Q:
        ans.append(i + 1)
if set(ans) == chach:
    print(*ans)
else:
    print(-1)