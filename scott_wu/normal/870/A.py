n, m = map(int, input().split())
s = set(map(int, input().split()))
t = set(map(int, input().split()))

if s & t:
    print(min(s & t))
else:
    a = min(s)
    b = min(t)
    print(str(min(a, b)) + str(max(a, b)))