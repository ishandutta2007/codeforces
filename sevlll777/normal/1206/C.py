n = int(input())
if n == 1:
    print('YES\n1 2')
elif n % 2 == 0:
    print('NO')
else:
    A = []
    B = []
    for i in range(n):
        if i % 2:
            A.append(2 * i + 2)
            B.append(2 * i + 1)
        else:
            A.append(2 * i + 1)
            B.append(2 * i + 2)
    print('YES')
    C = A + B
    print(' '.join(list(map(str, C))))