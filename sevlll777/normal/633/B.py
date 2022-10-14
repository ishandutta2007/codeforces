m = int(input())
c = 0
for i in range(5, 1000000, 5):
    x = i
    while x % 5 == 0:
        x //= 5
        c += 1
    if c == m:
        print(5)
        print(i, i + 1, i + 2, i + 3, i + 4)
        exit(0)
    elif c > m:
        print(0)
        exit(0)