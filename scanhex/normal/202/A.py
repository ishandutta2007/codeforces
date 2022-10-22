def palind(s):
    return s[:(len(s) + 1) // 2] == s[len(s) // 2:]
s = [i for i in input()]
maxx = ''
for mask in range(1 << len(s)):
    s2 = [s[i] for i in range(len(s)) if mask & (1 << i)]
    if palind(s2) and ''.join(s2) > maxx:
        maxx = ''.join(s2)
print(maxx)