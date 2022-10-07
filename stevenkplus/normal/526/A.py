def good(s, a, b):
  n = len(s)
  for i in range(5):
    j = a + i * b
    if j >= n:
      return False
    if s[j] != '*':
      return False
  return True

def go():  
  n = input()
  s = raw_input()
  for i in range(n):
    for j in range(1, n):
      if good(s, i, j):
        return True
  return False

if go():
  print 'yes'
else:
  print 'no'