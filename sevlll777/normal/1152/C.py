a, b = map(int, input().split())
a, b = min(a, b), max(a, b)
if b % a == 0:
    print(0)
    exit(0)
x = b - a
dels = set()
for i in range(1, int(x ** 0.5) + 1):
    if x % i == 0:
        dels.add(i)
        dels.add(x // i)
dels = list(dels)
j = 10 ** 20
for i in dels:
    if i >= a:
        j = min(j, i - a)
print(min((x % a - a) % x, j))