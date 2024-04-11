n, m, s = map(int, input().split())

def ceilDiv(a, b):
    return a // b + (0 if a % b == 0 else 1)

sgsx, sgsy = n % s, m % s

if sgsx == 0:
    sgsx = s

if sgsy == 0:
    sgsy = s

print(sgsx * sgsy * ceilDiv(n, s) * ceilDiv(m, s))