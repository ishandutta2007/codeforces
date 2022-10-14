n = int(input())
m = (n + 2) // 2
print(m)
for i in range(m):
    print(1, i + 1)
for i in range(n - m):
    print(m, i+2)