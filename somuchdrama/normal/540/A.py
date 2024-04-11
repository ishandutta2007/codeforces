n = int(input())
s = input()
t = input()
ans = 0
for i in range(n):
    a = int(s[i])
    b = int(t[i])
    if a >= b:
        ans += min(a - b, 10 + b - a)
    else:
        ans += min(b - a, 10 + a - b)
print(ans)