s = input()
x = max(s)
ans = x * s.count(x)
while s.rindex(x) < len(s) - 1:
    x1 = x
    x = max(s[s.rindex(x) + 1:])
    ans += x * s.count(x, s.rindex(x1))
print(ans)