a = list(map(int, input().split()))
b = a[1:]
b.sort()
n = 0
for i in range(10000000):
    n += 1
for i in b:
    print(i, end = " ")