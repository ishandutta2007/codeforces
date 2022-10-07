n = input()
cur, sm = 0, 0
ans = 0

while sm <= n:
  ans = cur
  cur += 1
  sm += cur * (cur + 1) / 2

print ans