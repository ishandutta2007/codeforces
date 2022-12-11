a = [1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0]
s = str(hex(int(input())))[2:]
ans = 0
for c in s:
    ans += a[int(c, 16)]
print(ans)