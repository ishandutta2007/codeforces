def x(a):
    return 1 if a == 0 else a * x(a-1)
n = input()
print x(2 * n - 2) / ((x(n - 1) ** 2))