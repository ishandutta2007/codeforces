def go():
  a = raw_input()
  b = 'CODEFORCES'
  j = len(b)
  if len(a) <= j:
    return False

  for i in range(j + 1):
    if a[:j - i] + a[len(a)-i:] == b:
      return True
  return False

print 'YES' if go() else 'NO'