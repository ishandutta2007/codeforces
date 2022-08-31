n,m = (int(s) for s in raw_input().split())

#print n
#print m

v = map(int, raw_input().split())
v.sort()
#print v

ans = 10000
for i in range(m-n+1):
    #print i
    ans = min (ans, v[i+n-1]-v[i])
print ans