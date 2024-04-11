n = int(raw_input())
for i in range(n):
    s = raw_input()
    if s[:5] == "miao." and s[-5:] != "lala.":
        print "Rainbow's"
    elif s[:5] != "miao." and s[-5:] == "lala.":
        print "Freda's"
    else:
        print "OMG>.< I don't know!"