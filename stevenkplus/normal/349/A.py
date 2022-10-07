def go():
  big, small = 0, 0 # num 50s, num 25s.

  n = input()
  ar = [int(_) for _ in raw_input().split()]

  for x in ar:
    if x == 100:
      if big > 0:
        x -= 50
        big -= 1
      need = (x - 25) / 25
      if need > small:
        return False
      else:
        small -= need
    elif x == 50:
      if small == 0:
        return False
      else:
        small -= 1
        big += 1
    else:
      small += 1

  return True

print "YES" if go() else "NO"