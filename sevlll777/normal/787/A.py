a, b = map(int, input().split())
c, d = map(int, input().split())
for i in range(b, 1000000, a):
    if i % c == d % c and i >= d:
        print(i)
        exit(0)
print(-1)