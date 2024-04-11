a, b, c = [input() for _ in range(3)]

def go(a, b):
  return max(a+b, a*b)

ans = max(go(go(a,b),c), go(go(b,c),a))
print ans