T = int(input())
for i in range(T):
  a, b, c = map(int, input().split())
  print(a + b + c, b + c, c)