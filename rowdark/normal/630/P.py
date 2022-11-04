from math import sin, cos, pi
from decimal import Decimal
n, r = map(int,raw_input().strip().split())
fx, fy = (cos(2 * Decimal(pi) * (n - 1) / n), sin(2 * Decimal(pi) * (n - 1) / n))
gx, gy = (cos(2 * Decimal(pi) * (n // 2) / n), sin(2 * Decimal(pi) * (n // 2) / n))
hx = (-fy * gx + gy * fx) / (gy - fy)
hy = 0
print "%.20f" %(-n * r * r * hx * gy)