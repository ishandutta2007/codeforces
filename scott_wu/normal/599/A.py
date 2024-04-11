a, b, c = map(int, raw_input().split())
print min (a + b + c, 2 * (a + b + c) - 2 * max ([a, b, c]))