n = int (input())
if n == 0:
    print(0)
else:
    n += 1;
    if n % 2 == 0:
        n //= 2
    print(n)