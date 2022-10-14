n = int(input())
A = list(map(int, input().split()))
ans = 1
colors = {}
for i in range(1, 11):
    colors[i] = 0
for j in range(n):
    i = A[j]
    colors[i] += 1
    q = []
    for elem in colors:
        if colors[elem]:
            q.append(colors[elem])
    q.sort()
    if len(q) == 1:
        ans = j + 1
    elif q[-1] == q[-2] + 1 and q[0] == q[-2]:
        ans = j + 1
    elif q[-1] == q[1] and q[0] == 1:
        ans = j + 1
print(ans)