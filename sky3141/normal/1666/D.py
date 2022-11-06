from collections import Counter

T = int(input())

for i in range(T):
    a, b = input().split()
    l = []
    d = Counter(b)
    for c in reversed(a):
        if d[c]:
            l.append(c)
            d[c] -= 1
    l.reverse()
    s = ''.join(l)
    print('YES' if s == b else 'NO')