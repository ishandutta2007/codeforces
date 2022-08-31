n, k = map (int, raw_input().split())
print min (i for i in xrange(1, 11) if (i * n) % 10 == k or (i * n) % 10 == 0)