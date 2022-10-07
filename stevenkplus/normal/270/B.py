n, ar = int(input()), [int(x) for x in input().split()][::-1]
ans = 0
for i in range(1, n):
  if ar[i] > ar[i - 1]: 
    ans = n - i
    break

print(ans)