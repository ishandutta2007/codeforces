A, B, C = map(int, raw_input().strip().split())
if A < 0:
    A = -A
    B = -B
    C = -C
D = (B ** 2 - 4 * A * C) ** .5
print "%.10f\n%.10f\n" %((-B + D) / 2 / A, (-B - D) / 2 / A)