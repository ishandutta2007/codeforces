n = int(input())
if n == 1:
    print(1)
    exit(0)
if n == 2:
    print(2)
    exit(0)
cnt = 0
for i in range(1, int(n ** 0.5) + 1):
    if n % i == 0 and i != n // i:
        cnt += 2
    elif n % i == 0:
        cnt += 1
print(cnt)