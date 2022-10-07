a, b = [int(x) for x in raw_input().split()]

ans = 0
left = 0
while a > 0:
  ans += a
  left += a
  a = left // b
  left = left % b
print ans