n = int(raw_input())
s = raw_input()
ans = 0
scal = 1
for i in s:
  ans += scal * (1 if i == 'B' else 0)
  scal *= 2
print ans