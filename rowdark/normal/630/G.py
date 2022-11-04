fact = lambda x: 1 if x == 0 else reduce(lambda x, y: x * y, range(1, x + 1))
C = lambda x, y: 0 if y < 0 or y > x else fact(x) // fact(y) // fact(x - y)
N = int(raw_input())
print (C(N, 5) + C(N, 1) * C(N - 1, 3) + C(N, 2) * C(N - 2, 1) + C(N, 1) * C(N - 1, 2) + C(N, 1) * C(N - 1, 1) + C(N, 1) * C(N - 1, 1) + C(N, 1)) * (C(N, 3) + C(N, 1) * C(N - 1, 1) + C(N, 1))