def rook(a, b):
  x = 0
  if a: x += 1
  if b: x += 1
  return x

def bish(a, b):
  x = 0
  a = abs(a)
  b = abs(b)
  if a == b:
    return 1
  if a % 2 == b % 2:
    return 2
  return 0

def king(a, b):
  a = abs(a)
  b = abs(b)
  return max(a, b)

r1, c1, r2, c2 = map(int, raw_input().split())
r1 -= r2
c1 -= c2
print str(rook(r1, c1)) + " " + str(bish(r1, c1)) + " " + str(king(r1, c1))