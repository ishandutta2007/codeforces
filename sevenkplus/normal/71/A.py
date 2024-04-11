n=input()
for i in xrange(n):
    s=raw_input()
    if len(s)>10:
        print s[0]+(len(s)-2).__str__()+s[len(s)-1]
    else:
        print s