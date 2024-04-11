import sys
n = int(input())
l, r = 0, n - 1
tmp, sum, pre = 0, 0, 0
while r - l > 1:
    m = (l + r) // 2
    print('+ ' + str( (m - tmp + n) % n ))
    
    sum += (m - tmp + n) % n
    tmp = m
    sys.stdout.flush()
    k = int(input())
    if k > pre:
        r = m
    else:
        l = m
    pre = k

print('! ' + str(n - r + sum))
sys.stdout.flush()