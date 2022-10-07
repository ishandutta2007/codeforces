n,m=map(int, raw_input().split())
p=map(int, raw_input().split())
for t in xrange(m):
    y=0
    l,r,s=map(int, raw_input().split())
    for i in range(l-1, r):
        if p[i]<p[s-1]:
            y+=1
    if y==s-l:
          print 'Yes'
        
    else:
        print 'No'