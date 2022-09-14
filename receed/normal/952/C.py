def check(d):
    for i in range(1, len(d)):
        if abs(d[i - 1] - d[i]) > 1:
            return 1
    return 0

n = int(input())
a = [int(i) for i in input().split()]
b = []
ans = 0
ans = ans or check(a)
for i in range(n):
    mx = max(a)
    a.pop(a.index(mx))
    b.append(mx)
    ans = ans or check(a)
ans = ans or check(b)
print(['YES', 'NO'][ans])