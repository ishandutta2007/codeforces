PMAX = 300

isPrime = [False for i in range(PMAX)]

for i in range(2, PMAX):
    isPrime[i] = True

for i in range(2, PMAX):
    if isPrime[i]:
        for j in range(2 * i, PMAX, i):
            isPrime[j] = False

n = int(input())

primeToTake = [p for p in range(PMAX) if isPrime[p]][:n]

product = 1
for x in primeToTake:
    product *= x

if n == 2:
    print(-1)
else:
    print(*[product//p for p in primeToTake], sep="\n")