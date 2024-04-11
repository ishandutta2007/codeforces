__author__ = 'Alex'
n = int(input())
a = [int(i) for i in input().split()]
a.sort()
s = 10
i = 0
while i < n and a[i] + s <= 360:
    s += a[i]
    i += 1
ans = 0
while i < n and a[i] + s <= 720:
    s += a[i]
    ans += s - 360
    i += 1
print(i, ans)