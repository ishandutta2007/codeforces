
n = int(raw_input())
s = [set()] * n
for i in range(n):
  k = [x for x in raw_input().split()][1::]
  s[i] = set(k)

for i in range(n):
  good = 1
  for j in range(n):
    if i != j and s[i].issuperset(s[j]):
      good = 0
  if good: print "YES"
  else: print "NO"