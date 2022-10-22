n = input()

L = map(int , raw_input().split(' '))
R = map(int , raw_input().split(' '))
d = set(L[1:] + R[1:])

if len(d) == n:
    print 'I become the guy.'
else:
    print 'Oh, my keyboard!'