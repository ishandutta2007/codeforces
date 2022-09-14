def tri(ar):
    d={'.':0,'x':0,'o':0}
    for i,j in ar:
        d[a[i][j]]+=1
    if d['.']==1 and d['x']==2:
        ans[0]='YES'
    #print(d)
        
ans=['NO']
a=[input() for i in range(4)]
for i in range(2):
    for j in range(2):
        tri([(i,j),(i+1,j+1),(i+2,j+2)])
    for j in range(2,4):
        tri([(i,j),(i+1,j-1),(i+2,j-2)])
for i in range(4):
    for j in range(2):
        tri([(i,j),(i,j+1),(i,j+2)])
        tri([(j,i),(j+1,i),(j+2,i)])
print(ans[0])