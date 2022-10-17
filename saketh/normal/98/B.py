from fractions import *

N = int(raw_input())

start = 0
while N % 2 == 0:
    start += 1
    N /= 2

if N == 1:
    print "%d/1" % start
    exit(0)

pos = 1
steps = 0

pr = 0
ex = 0
dn = 1

while True:
    pos *= 2
    steps += 1

    pr *= 2
    ex *= 2
    dn *= 2

    if pos >= N:
        ex = ex + (dn - pr) * N / pos * steps
        pr = pr + (dn - pr) * N / pos

        #ex = ex + (1 - pr) * Fraction(N, pos) * steps
        #pr = pr + (1 - pr) * Fraction(N, pos)
        pos -= N

    if pos == 1:
        break

pr = Fraction(pr, dn)
ex = Fraction(ex, dn)
ans = (ex + (1 - pr) * steps) / pr
print start + ans