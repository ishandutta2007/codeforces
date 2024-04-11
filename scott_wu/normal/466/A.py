n, m, a, b = map (int, raw_input().split())
print min ([n * a, n / m * b + (n % m) * a, (n / m + 1) * b])