n, m, a = map(int, input().split())
from math import ceil
print(int(ceil(n / a) * ceil(m / a)))