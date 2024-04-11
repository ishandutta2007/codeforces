N = int(raw_input())
M = 2 * N - 2
A = 4 ** (N - 3)
B = 0 if N == 3 else 4 ** (N - 4)
print 4 * 3 * A * 2 + 4 * 3 * 3 * B * (N - 3)