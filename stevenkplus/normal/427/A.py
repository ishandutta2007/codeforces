n = input()
ar = [int(x) for x in raw_input().split()]
ans = 0
cnt = 0
for x in ar:
  if x == -1:
    if cnt > 0:
      cnt -= 1
    else:
      ans += 1
  else:
    cnt += x
print ans