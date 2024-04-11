n, k = map (int, raw_input().split())
if n % (2 * k) >= k:
    print "YES"
else:
    print "NO"