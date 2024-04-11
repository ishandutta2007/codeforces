a, b, c = map(int, raw_input().strip().split())
sa = 2 ** .5 / 12
sb = 2 ** .5 / 6
sc = (25 + 10 * 5 ** .5) ** .5 * ((5 - 5 ** .5) / 10) ** .5 / 12
print "%.12f" %(sa * a ** 3 + sb * b ** 3 + sc * c ** 3)