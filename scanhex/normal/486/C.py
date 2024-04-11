n, p = [int(i) for i in input().split()]
p -= 1
p = min(p, n - p - 1)
s = input()
ans = 0
m1 = None
m2 = 0
for i in range(n):
    if n - i - 1 < i:
        break
    if s[i] != s[-i - 1]:
        if m1 is None:
            m1 = i
        m2 = max(m2, i)
    ans += min(abs(ord(s[i]) - ord(s[-i - 1])), 26 - abs(ord(s[i]) - ord(s[-i - 1])))
if m1 is None:
    print(0)
    exit(0)
if m2 <= p:
    x = p - m1
elif m1 >= p:
    x = m2 - p
else:
    x = min(2 * (m2 - p) + p - m1, 2 * (p - m1) + m2 - p)
print(ans + x)