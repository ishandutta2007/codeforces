from itertools import permutations
def good(s, t, r):
    for i in range(len(s) - 1):
        pa = s[i:i + 2]
        if pa == t or pa == r:
            return False
    return True

n = int(input())
s = input()
t = input()
l = []
for p in permutations('abc'):
    l.append(p[0]*n + p[1]*n + p[2]*n)
    l.append((p[0] + p[1] + p[2]) * n)
print('YES')
for x in l:
    if(good(x, s, t)):
        print(x)
        exit()