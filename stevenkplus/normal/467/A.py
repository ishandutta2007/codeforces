n = int(raw_input())
ans = 0
for i in range(n):
  x, y = [int(k) for k in raw_input().split()]
  if x + 2 <= y:
    ans += 1
print ans