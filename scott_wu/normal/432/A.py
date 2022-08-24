n, k = map (int, raw_input().split())
print sum (i + k <= 5 for i in map (int, raw_input().split())) / 3