n = int(input())
for i in range(int(n ** 0.5), 0, -1):
    if n % i == 0:
        print(i, n // i)
        exit(0)