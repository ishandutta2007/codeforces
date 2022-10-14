#saved
n, k = map(int, input().split())
if n == k:
    print('1' * n)
elif k == 1:
    print('0' + '1' * (n - 1))
else:
    x = (n - k) // 2
    a = '0' * x + '1'
    print(a * (n // (x + 1)) + '0' * (n % (x + 1)))