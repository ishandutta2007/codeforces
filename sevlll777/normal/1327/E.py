n = int(input())
if n == 1:
    print(10)
elif n == 2:
    print(180, 10)
elif n == 3:
    print(2610, 180, 10)
elif n == 4:
    print(34200, 2610, 180, 10)
else:
    M = 998244353
    B = [0] * (n + 1)
    B[1] %= M
    B[n] = 10
    B[n-1] = 180
    B[n-2] = 2610
    for i in range(1, n-2):
        B[i] = 10 * (18 * pow(10, n - i - 1, M) % M + (n-i-1) * 81 * pow(10, n-i-2, M)) % M
        B[i] %= M
    for i in range(len(B)):
        B[i] %= M
    print(*B[1:])