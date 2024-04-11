s = list(input())
f = -1
for inf in range(len(s)):
    i = s[inf]
    if int(i) % 2 == 0:
        f = inf
        if int(i) < int(s[-1]):
            s[inf], s[-1] = s[-1], s[inf]
            print(''.join(s))
            exit(0)
if f == -1:
    print(-1)
else:
    s[f], s[-1] = s[-1], s[f]
    print(''.join(s))