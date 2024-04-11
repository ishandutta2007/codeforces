def opt1(n):
    k = n // 2
    res = 1
    for i in range(k + 1, n + 1):
        res *= i
    for i in range(2, k + 1):
        res //= i
    return res
def opt2(n):
    res = 1
    for i in range(1, n + 1):
        res *= i
    if n == 1:
        return 1
    if n == 2:
        return 1
    return res // n
n = int(input())
print(opt1(n) * opt2(n // 2) * opt2(n // 2) // 2)