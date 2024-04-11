n, m = (int (s) for s in raw_input().split())

ans, last = 0, 1

arr = map (int, raw_input().split())

#print arr

for cur in arr:
    ans += cur - last
    if cur < last:
        ans += n
    last = cur

print ans