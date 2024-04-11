from collections import defaultdict
import math

for _ in range(int(input())):
  n = int(input())
  l = list(map(int, input().split()))
  MAX = 0
  d = defaultdict(int)
  d[0] = 0
  for i in range(n):
    d[l[i]] += 1
  MAX = 0
  for i, v in d.items():
    MAX = max(MAX, v)
  t = n - MAX
  a = 0
  while MAX < n:
    MAX *= 2
    a += 1
  print(a+t)