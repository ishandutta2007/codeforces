n = input()
r = [int(x) for x in raw_input().split()]

c = [1 for x in r if x % 2 == 1]
if c:
    print "First"
else:
    print "Second"