px, py, vx, vy, a, b, c, d = map(int, raw_input().strip().split())
f = (vx ** 2 + vy ** 2) ** .5
ux = vx / f
uy = vy / f
print "%.10f %.10f" %(px + ux * b, py + uy * b)
print "%.10f %.10f" %(px - uy * a / 2, py + ux * a / 2)
print "%.10f %.10f" %(px - uy * c / 2, py + ux * c / 2)
print "%.10f %.10f" %(px - uy * c / 2 - ux * d, py + ux * c / 2 - uy * d)
print "%.10f %.10f" %(px + uy * c / 2 - ux * d, py - ux * c / 2 - uy * d)
print "%.10f %.10f" %(px + uy * c / 2, py - ux * c / 2)
print "%.10f %.10f" %(px + uy * a / 2, py - ux * a / 2)