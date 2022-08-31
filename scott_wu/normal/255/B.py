s = raw_input()

xc = s.count ('x')
yc = s.count ('y')

if xc > yc:
    print 'x' * (xc - yc)
else:
    print 'y' * (yc - xc)