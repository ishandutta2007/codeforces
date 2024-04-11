n = input()
ar = [int(x) for x in raw_input().split()]

ar.sort()
mult = 2
ans = 0
for x in ar:
  ans += mult * x
  mult += 1

ans -= ar[-1]
print ans