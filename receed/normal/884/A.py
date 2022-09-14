n, t = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
s = 0
for i in range(n):
    s += 86400 - a[i]
    if s >= t:
        print(i + 1)
        break