a, b = map(int, input().split())
print(sum((1 if b // i <= a and b % i == 0 else 0) for i in range(1, a + 1)))