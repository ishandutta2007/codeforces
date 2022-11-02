n = input()
a = map(int, raw_input().split())

MIN = a[0]
MAX = a[0]

ans = 0

for i in xrange(1,n):
    if a[i]>MAX:
        ans += 1
        MAX = a[i]
    if a[i]<MIN:
        ans += 1
        MIN = a[i]
print ans