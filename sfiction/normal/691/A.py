n = max(2, int(raw_input()))
print 'YES' if n == sum(map(int, raw_input().split())) + 1 else 'NO'