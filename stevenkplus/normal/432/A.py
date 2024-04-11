def go(ar):
  if len(ar) < 3: return False
  ar.sort(reverse=True)
  if ar[2] > 0:
    ar[:3] = [0]*3
    return True
  else:
    return False


n,k = [int(_) for _ in raw_input().split()]
ar = [(5 - int(_)) // k for _ in raw_input().split()]

ans = 0
while go(ar):
  ans += 1

print ans