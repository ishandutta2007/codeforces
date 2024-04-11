n,m = map(int, raw_input().split())
s1 = map(int, raw_input().split())
s2 = map(int, raw_input().split())

p1, p2 = 0, 0
while p1 < len(s1) and p2 < len(s2):
  if s1[p1] > s2[p2]: p2 += 1
  else: 
    p2 += 1
    p1 += 1

left = len(s1) - p1
print max(left, n - m)