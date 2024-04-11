n, m, k = map(int, input().split())
D = list(map(int, input().split()))
com = list(map(int, input().split()))
com = set(com)
ans = []
for i in range(m):
    lol = 0
    aa = 0
    for j in com:
        if j % D[i] == 0:
            aa += 1
    ans.append((aa, 1+i))
ans.sort()
p = [ans[0][1]]
for c in range(1, len(ans)):
    if ans[c][0] != ans[c-1][0]:
        break
    p.append(ans[c][1])
print(len(p))
print(*p)