n = input()
a = [1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0]
#    0 1 2 3 4 5 6 7 8 9 A B C D E F
s = 0
if (n == 0):
    s += 1
while n > 0:
    s += a[n % 16]
    n /= 16
print s