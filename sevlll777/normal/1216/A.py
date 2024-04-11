n = int(input())
s = input()
t = ''
op = {'a': 'b', 'b': 'a'}
ans = 0
for i in range(n // 2):
    if s[2 * i] == s[2 * i + 1]:
        ans += 1
    t += s[2 * i]
    t += op[s[2 * i]]
print(ans)
print(t)