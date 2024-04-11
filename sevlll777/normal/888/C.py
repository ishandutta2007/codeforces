from copy import copy
s = input()
alphabet = 'qwertyuioplkjhgfdsazxcvbnm'
anss = len(s)
for sim in alphabet:
    x = copy(s)
    x = x.split(sim)
    ans = 0
    for i in x:
        ans = max(ans, len(i))
    anss = min(anss, ans)
print(anss + 1)