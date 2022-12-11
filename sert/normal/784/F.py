x = 1
for i in range(10000000): x = x + 1
print(' '.join(map(str, sorted(list(map(int, input().split()))[1:]))))