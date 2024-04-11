a, b, c = raw_input(), raw_input(), raw_input()

d = {}
for x, y in zip (a, b):
    d[x] = y
    d[x.upper()] = y.upper()


ans = ""
for x in c:
    if x in d:
        ans += d[x]
    else:
        ans += x
print ans