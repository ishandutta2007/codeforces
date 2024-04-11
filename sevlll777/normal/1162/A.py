n, h, m = map(int, input().split())
kek = [h] * n
for i in range(m):
    l, r, x = map(int, input().split())
    for q in range(l - 1, r):
        kek[q] = min(kek[q], x)
cnt = 0
for u in kek:
    cnt += u ** 2
print(cnt)