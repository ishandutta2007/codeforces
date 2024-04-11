a, b = raw_input(), raw_input()
if a == b:
    print -1
else:
    print len(a) if len(a) > len(b) else len(b)