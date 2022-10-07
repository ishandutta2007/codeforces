n = [int(_) for _ in raw_input()]
k = max(n)

print k

ar = []
for i in range(k):
  cur = 0
  for j in range(len(n)):
    cur = cur * 10
    if n[j] > 0:
      cur += 1
      n[j] -= 1
  ar += [cur]

print ' '.join([str(x) for x in ar])