n, m = map (int, raw_input().split())

a = 0
for i in xrange(n):
    a += sum(c in ['C', 'M', 'Y'] for c in raw_input().split())
print ('#Black&White' if not a else '#Color')