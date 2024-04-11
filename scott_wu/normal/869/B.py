a, b = map(int, input().split())

x = 1
for i in range(a+1, b + 1):
    x *= i
    x = x % 10
    if x == 0:
        break
print(x)