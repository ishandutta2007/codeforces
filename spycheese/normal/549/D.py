n, m = map(int,input().split())
ss = [input() for i in range(n)]
s = []
add = []
for i in range(n):
    s.append([])
    add.append([])
    for j in range(m):
        s[i].append((1 if (ss[i][j] == "B") else -1))
        add[i].append(0)

rm = range(m-1, -1, -1)

ans = 0
for i in range(n-1, -1, -1):
    cadd = 0
    for j in rm:
        cadd += add[i][j]
        x = cadd+s[i][j]
        if x != 0:
            ans += 1
            cadd -= x
            for k in range(i):
                add[k][j] -= x

print(ans)