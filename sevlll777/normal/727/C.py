from sys import stdout
n = int(input())
print('?', 1, 2)
a = int(input())
stdout.flush()
print('?', 2, 3)
b = int(input())
stdout.flush()
print('?', 1, 3)
c = int(input())
stdout.flush()
A = [(a + c - b) // 2, (a + b - c) // 2, (b + c - a) // 2]
for i in range(4, n + 1):
    print('?', 1, i)
    m = int(input())
    stdout.flush()
    A.append(m - A[0])
print('!', *A)