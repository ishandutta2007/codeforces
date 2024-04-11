n = int(raw_input())

a, b = [], []
for i in range(n):
    x, y = (int(s) for s in raw_input().split())
    a.append(x)
    b.append(y)

ans = ""
for i in range(n):
    if i < n / 2 or a[i] < b[n-1-i]:
        ans += '1'
    else:
        ans += '0'

ans += '\n'

for i in range(n):
    if i < n / 2 or b[i] < a[n-1-i]:
        ans += '1'
    else:
        ans += '0'

print ans