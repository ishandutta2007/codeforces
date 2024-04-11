for _ in range(int(input())):
    n, m = map(int, input().split())
    A = []
    x = 1
    while True:
        if (m * x) % 10 not in A:
            A.append((m * x) % 10)
        else:
            break
        x += 1
    s = sum(A)
    n //= m
    print(s * (n // len(A)) + sum(A[:n % len(A)]))