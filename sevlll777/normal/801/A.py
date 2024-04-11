s = list(input())
ans = (''.join(s)).count('VK')
for i in range(len(s)):
    t = s.copy()
    sus = {'V', 'K'}
    sus.discard(s[i])
    t[i] = sus.pop()
    ans = max(ans, (''.join(t)).count('VK'))
print(ans)