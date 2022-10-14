n = int(input())
GR = list(map(int, input().split()))
ANDR = list(map(int, input().split()))
h = {}
k = {}
for y in range(1, n):
    if GR[y] - GR[y - 1] not in h:
        h[GR[y] - GR[y - 1]] = 0
    h[GR[y] - GR[y - 1]] += 1
for y in range(1, n):
    if ANDR[y] - ANDR[y - 1] not in k:
        k[ANDR[y] - ANDR[y - 1]] = 0
    k[ANDR[y] - ANDR[y - 1]] += 1
if h == k and ANDR[0] == GR[0] and ANDR[-1] == GR[-1]:
    print('yes')
else:
    print('no')