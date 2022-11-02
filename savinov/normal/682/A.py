n, m = map(int, raw_input().split())

a1 = [0] * 5
a2 = [0] * 5

for i in xrange(1, n + 1):
    a1[i % 5] += 1
for i in xrange(1, m + 1):
    a2[i % 5] += 1

ans = 0

for i in xrange(5):
    for j in xrange(5):
        if (i + j) % 5 == 0:
            ans += a1[i] * a2[j]

print ans