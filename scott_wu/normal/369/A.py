n, m, k = (int(s) for s in raw_input().split())

for i in map (int, raw_input().split()):
    #print i
    if i == 2 and k > 0:
        k -= 1
    else:
        m -= 1

print max (0, -m)