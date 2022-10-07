from collections import Counter
def go():
  n = int(input())
  d = Counter()
  for c in input():
    d[c] += 1
  if d['I'] == 0: return d['A']
  elif d['I'] == 1: return 1
  else: return 0

print(go())