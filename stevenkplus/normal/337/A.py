n, m = [int(x) for x in raw_input().split()]

ar = [int(x) for x in raw_input().split()]
ar.sort()


ans = 99999

for i in range(m - n + 1):
  diff = ar[i + n - 1] - ar[i]
  if diff < ans:
    ans = diff

print ans