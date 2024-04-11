t = int(input())
for i in range(t):
    [n, k] = [int(x) for x in input().split()]
    if n % k == 0:
        print(1)
        continue

    curr = k - n % k
    print(curr // n + bool(curr % n) + 1)