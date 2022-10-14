w, h = map(int, input().split())
u1, d1 = map(int, input().split())
u2, d2 = map(int, input().split())
for t in range(h, 0, -1):
    w += t
    if t==d1:
        w -= u1
        w = max(0, w)
    elif t==d2:
        w -= u2
        w = max(0, w)
print(w)