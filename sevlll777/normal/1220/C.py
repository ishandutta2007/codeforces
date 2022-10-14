s = input()
m = chr(ord('z') + 1)
ans = []
f = 0
for i in s:
    if i > m:
        ans.append('Ann')
    else:
        ans.append('Mike')
    m = min(m, i)
print('\n'.join(ans))