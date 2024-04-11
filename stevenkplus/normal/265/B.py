n = int(input())
cur = 0
sum = 0
for i in range(n):
  nxt = int(input())
  sum += abs(nxt - cur)
  cur = nxt
  sum += 1
  if i + 1 < n: sum += 1
print (sum)