n, m = map (int, raw_input().split())
k = map (int, raw_input().split())

l = 0
while l < m - 1:
  l = l + k[l];
print "Yes" if l == m - 1 else "No"