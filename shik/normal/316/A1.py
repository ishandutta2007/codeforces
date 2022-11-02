s = raw_input()
c1 = list(s).count('?')
c2 = len(set("ABCDEFGHIJ") & set(s))
ans = 1
ans *= 10 ** c1
now = 10
while c2 > 0:
    ans *= now
    c2 -= 1
    now -= 1

if s[0] in "?ABCDEFGHIJ":
    ans /= 10
    ans *= 9

print ans