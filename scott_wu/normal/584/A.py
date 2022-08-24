n, t = raw_input().split()

if n == '1' and t == '10':
    print -1
elif len(t) == 1:
    print t * int(n)
else:
    print "1" + "0" * (int(n) - 1)