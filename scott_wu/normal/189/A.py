n, a, b, c = map (int, raw_input().split())
c, b, a = sorted ((a, b, c))
print max (i + j + ((n - i * a - b * j) / c) for i in xrange(min (b, (n + 1) / a + 1)) for j in xrange(min (c, (n + 1) / b + 1)) if (n - i * a - b * j) % c == 0)