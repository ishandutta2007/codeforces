n = input()
x = 100000
s = 0
for i in xrange(n):
    a , b = map(int , raw_input().split(' '))
    x = min(x , b)
    s += a * x
print s