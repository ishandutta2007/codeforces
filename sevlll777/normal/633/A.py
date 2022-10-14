a, b, c = map(int, input().split())
for d1 in range(5002):
    for d2 in range(5002):
        if a * d1 + b * d2 == c:
            print('Yes')
            exit(0)
print('No')