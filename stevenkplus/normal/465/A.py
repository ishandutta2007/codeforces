n = [int(_) for _ in raw_input().split()]
s = raw_input()

ans = 1
for i in s:
  if i == '1':
    ans += 1
  else: break

if ans > len(s):
  ans = len(s)

print ans