n, m,k = map(int, input().split())
h=list(map(int,input().split()))
h=set(h)
now = 1
if 1 in h:
    print(1)
    exit(0)
for _ in range(k):
    u, v = map(int, input().split())
    if u == now:
        now = v
    elif v == now:
        now = u
    if now in h:
        print(now)
        exit(0)
print(now)