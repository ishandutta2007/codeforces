n, w = map(int, raw_input().split())
a = map(int, raw_input().split())
a.sort()
print "%.10f" %(min(w / 3. / n, a[0], a[n] / 2.) * 3 * n)