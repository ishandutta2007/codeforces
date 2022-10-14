n = int(input())
h = 0
for i in range(n):
    s, d = map(int, input().split())
    h = max(s, h + d - (h - s) % d)
print(h)