n, m = map(int, input().split())
B = list(map(int, input().split()))
G = list(map(int, input().split()))
if min(G) < max(B):
    print(-1)
    exit(0)
cnt = 0
z = max(B)
y = 0
f = 1
f2 = 0
for i in B:
    if i != z or f2:
        y = max(y, i)
    else:
        f2 = 1
for i in G:
    if i == z:
        f = 0
    cnt += i - z
if f:
    cnt += z - y
print(cnt + sum(B) * m)