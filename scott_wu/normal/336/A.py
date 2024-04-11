x, y = (int(s) for s in raw_input().split())

if x > 0:
    if y > 0:
        print str(0) + " " + str(x+y) + " " + str(x+y) + " " + str(0)
    else:
        print str(0) + " " + str(y-x) + " " + str(x-y) + " " + str(0)
else:
    if y > 0:
        print str(x-y) + " " + str(0) + " " + str(0) + " " + str(y-x)
    else:
        print str(x+y) + " " + str(0) + " " + str(0) + " " + str(x+y)