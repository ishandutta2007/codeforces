n, m = (int(s) for s in raw_input().split())

a = map (int, raw_input().split())
b = map (int, raw_input().split())

t = max (max(a), 2 * min(a))
if t >= min(b):
    print -1
else:
    print t