a, b, c, d = [int(x) for x in raw_input().split()]
p = float(a) / b
q = float(c) / d

fail = (1 - p) * (1 - q)
ans = p / (1 - fail)
print "%.8f" % ans