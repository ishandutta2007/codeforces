a, b, c = [int(i) for i in input().split()]
print(min(a + b + c, a + a + b + b, 2 * a + 2 * c, 2 * b + 2 * c))