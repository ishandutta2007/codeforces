for s in[*open(0)][2::2]:
 d={};i=0;r=1
 for x in s.split():r+=r>i;r=min(r,i-d.get(x,-r));d[x]=i;i+=1
 print(i-r)