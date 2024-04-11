n, h = map (int, raw_input().split())
arr = map (int, raw_input().split())
print n + sum (1 for x in arr if x > h)