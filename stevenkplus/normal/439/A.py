def go():
  n, d = [int(_) for _ in raw_input().split()]
  ar = [int(_) for _ in raw_input().split()]

  tot = sum(ar) + 10 * (len(ar) - 1)
  if tot > d:
    return -1
  else:
    return (d - sum(ar)) // 5


print go()