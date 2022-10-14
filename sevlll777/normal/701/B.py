n, m = map(int, input().split())
stolb = set()
strok = set()
for i in range(m):
    x, y = map(int, input().split())
    stolb.add(x)
    strok.add(y)
    print(n * n - n * len(strok) - n * len(stolb) + len(strok) * len(stolb), end=' ')