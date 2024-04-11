n = int(input())
if n % 2:
    print(0)
else:
    a = [1, 2, 4, 3]
    b = [1, 3, 4, 2]
    c = [1, -1]
    print((1 + a[n % 4] + b[n % 4] + c[n % 2]) % 5)