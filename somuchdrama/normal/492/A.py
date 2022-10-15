n = int(input())
c = 0
for i in range(1, 10000):
    s = 0
    for j in range(1, i + 1):
        s += j
    c += s
    if c > n:
        print(i - 1)
        break
    elif c == n:
        print(i)
        break