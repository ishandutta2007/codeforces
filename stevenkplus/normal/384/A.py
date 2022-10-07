def go(n):
  x = 'C.' * n
  ret = ""
  for i in range(n):
    if i % 2 == 0:
      ret += x[:n]
    else:
      ret += x[1:n+1]
    ret += '\n'
  return ret

n = input()
ans = go(n)
num = sum(1 for _ in ans if _ == 'C')

print num
print ans