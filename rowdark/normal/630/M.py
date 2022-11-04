N  = (-int(raw_input()) % 360 + 360) % 360
ans = 0
tmp = min(N, 360 - N)
for i in xrange(4):
    if tmp > min(N, 360 - N):
        tmp = min(N, 360 - N)
        ans = i
    N += 90
    if N >= 360: N -= 360
print ans