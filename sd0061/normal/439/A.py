n , d = map(int , raw_input().split(' '))
s = sum(map(int , raw_input().split(' ')))
if s + (n - 1) * 10 > d:
    print -1
else:
    print 2 * (n - 1) + (d - s - (n - 1) * 10) / 5