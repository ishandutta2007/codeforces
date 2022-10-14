n = int(input())
if n == 1:
    print('YES\n1')
    exit(0)
if n == 4:
    print('YES\n1 3 2 4')
    exit(0)
for p in range(2, int(n ** 0.5) + 1):
    if n % p == 0:
        print('NO')
        exit(0)
print('YES')
print(1)
for j in range(2, n):
    print(j * pow(j - 1, n - 2, n) % n)
print(n)