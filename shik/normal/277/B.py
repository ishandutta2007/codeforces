n, m = map(int, raw_input().split())
if m == 3 and n >= 5:
    print -1
else:
    for i in range(m):
        print i, i * i
    for i in range(n - m):
        print i * i + 514514, i