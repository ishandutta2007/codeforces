a, b, c, d, e, f = map(int, raw_input().split(" "))
side = a + b + c
f = lambda x: x ** 2
area = side ** 2 - f(a) - f(c) - f(e)
print area