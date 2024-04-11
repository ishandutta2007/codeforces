n = int(raw_input())
a = [""] * n
ans = 1
for i in range(n):
    a[i] = raw_input()
for i in range(n):
    if i + 1 < n:
        ans += a[i] != a[i + 1]
print ans