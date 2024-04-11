n = int(input())
if n <= 2:
    print(-1)
else:
    c = 0
    while n % 2 == 0:
        c += 1
        n //= 2
    if n == 1:
        print(3 * 2 ** (c - 2), 5 * 2 ** (c - 2))
    else:
        print(2 ** c * (n ** 2 // 2), 2 ** c * ((n ** 2 + 1) // 2))