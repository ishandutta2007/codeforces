n, k = map (int, raw_input().split())
print max(x for x in xrange(n + 1) if (x * (x + 1) / 2 * 5 + k) <= 240)