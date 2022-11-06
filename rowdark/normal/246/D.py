q = [set({}) for i in range(0, 100002)]
s = raw_input().split()
n = int(s[0])
m = int(s[1])
s = raw_input().split()
c = [int(s[i]) for i in range(0, n)]
while m != 0:
    m -= 1
    s = raw_input().split()
    x = int(s[0]) - 1
    y = int(s[1]) - 1
    if c[x] != c[y]:
        q[c[x]] |= {c[y]}
        q[c[y]] |= {c[x]}
ans = 0
anss = 0
for i in range(1, 100001):
    if len(q[i]) > ans:
        ans = len(q[i])
        anss = i
if anss == 0:
    c.sort()
    anss = c[0]
print(anss)