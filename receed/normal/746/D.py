n,k,a,b=[int(i) for i in input().split()]
ans=[]
if a>=b:
    gr=[k]*(a//k)
    if a%k>0:
        gr.append(a%k)
    if len(gr)>1:
        x=b//len(gr)
        y=b%len(gr)
        bl=[x+1]*y+[x]*(len(gr)-y)
    else:
        bl=[b]
    for i in range(len(gr)):
        ans.extend(['G']*gr[i])
        ans.extend(['B']*bl[i])
else:
    gr=[k]*(b//k)
    if b%k>0:
        gr.append(b%k)
    if len(gr)>1:
        x=a//len(gr)
        y=a%len(gr)
        bl=[x+1]*y+[x]*(len(gr)-y)
    else:
        bl=[a]
    for i in range(len(gr)):
        ans.extend(['B']*gr[i])
        ans.extend(['G']*bl[i])
ans=''.join(ans)
if 'G'*(k+1) in ans or 'B'*(k+1) in ans:
    print('NO')
else:
    print(ans)