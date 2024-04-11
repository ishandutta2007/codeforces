n, m, k = map (int, raw_input().split())

print max (0, k * (k + 1) / 2 * n - m)