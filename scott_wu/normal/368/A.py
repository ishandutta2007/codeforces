n, d = (int(s) for s in raw_input().split())
arr = map (int, raw_input().split())
m = int(raw_input())

'''print arr'''

arr.sort()

#print arr

ans = 0
for i in xrange(min (m, n)):
    ans += arr[i]

#print arr
#print m
#print n
#print d

if m > n:
    ans -= d * (m - n)

print ans