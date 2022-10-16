import decimal

n, p = input().split(' ')
n = int(n)
p = decimal.Decimal(p)

ans = n - 1
for k in range(0, n):
  p1 = (decimal.Decimal(n-k)*(n-k-1)*k*3) / (n*(n-1)*(n-2)*2)
  p2 = (decimal.Decimal(n-k)*k*(k-1)*3) / (n*(n-1)*(n-2))
  p3 = (decimal.Decimal(k-1)*(k-2)*k) / (n*(n-1)*(n-2))

  # print(p1, p2, p3, ' - ')

  if p1 + p2 + p3 >= p:
    ans = k
    break
  
print(ans)