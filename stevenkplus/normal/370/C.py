n,m = map(int, raw_input().split())
s = [int(x) for x in raw_input().split()]
s.sort()
c = [0] * 111
bst = 0
for i in s:
  c[i] += 1
  bst = max(bst, c[i])

print min(n, 2 * (n - bst))

for i in range(n):
  print str(s[i]) + " " + str(s[(i + n // 2) % n])