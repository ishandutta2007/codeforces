maxn = 100100
ar = [1 for i in range(maxn)]
ar[0], ar[1] = 0, 0

for i in range(2, maxn):
  if ar[i]:
    for j in range(i, (maxn - 1) // i + 1):
      ar[i * j] = 0

dst = maxn
d = [dst for i in range(maxn)]

for i in reversed(range(maxn)):
  if ar[i]: dst = 0
  d[i] = min(d[i], dst)
  dst += 1

n, m = map(int, input().split())
g = [[int(x) for x in input().split()] for _ in range(n)]
g = [[d[x] for x in y] for y in g]
tmpsharon = min([sum(x) for x in g] + [sum(x) for x in zip(*g)])
print(tmpsharon)