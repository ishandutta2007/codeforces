n = int(raw_input())

#print n

ans = [None] * n
arr = map (int, raw_input().split())

#print arr

g = []
for i in range(n):
    #print i
    #print arr[i]
    #print 1e9 * arr[i] + i
    #print int(1e9 * arr[i] + i)
    g.append (1000000 * arr[i] + i)

#print g

g.sort()
lval = 0

for i in g:
    lval = max (lval + 1, i / 1000000)
    ans[i % 1000000] = lval
    '''
    #print str(i[1]) + " " + str(i[0])
    #print last
    a = i / int(1e9)
    b = i % int(1e9)
    
    #print i
    #print (a, b)
    if a <= lval:
        a = lval + 1
    #print i
    ans[b] = a
    lval = a
    '''

print ' '.join(map(str, ans))