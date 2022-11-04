fact = lambda x: 1 if x == 0 else reduce(lambda a, b: a * b, range(1, x + 1))
N = int(raw_input())
print sum(map(lambda x: fact(N) // fact(x) // fact(N - x), range(5, 8)))