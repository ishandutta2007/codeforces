def go():
  for i in range(8):
    s = input()
    prv = 0
    for j in s:
      if j == prv: return False
      prv = j
  return True

print ("YES" if go() else "NO")