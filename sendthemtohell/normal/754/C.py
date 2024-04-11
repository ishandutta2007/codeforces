from sys import *

t=int(stdin.readline())
for sssss in range(t):
    text,ps,dn,n,names,m=[],[],dict(),int(stdin.readline()),stdin.readline().split(),int(stdin.readline())
    for i in range(len(names)):
        dn[names[i]]=i
    for i in range(m):
        nxt=stdin.readline()
        getname=nxt.split(":")[0]
        nxt=nxt.split(":")[1]
        text.append(nxt)
        if getname=="?":
            pos,hell,shit=set([z for z in range(n)]),"",set([".",",","!","?"])
            for y in nxt:
                if y in shit:
                    hell+=" "
                else:
                    hell+=y
            nhere=hell.split()
            for j in nhere:
                pos.discard(dn.get(j))
            if i and len(ps[-1])==1:
                for dd in ps[-1]:
                    pos.discard(dd)
            ps.append(pos)
        else:
            if i:
                ps[-1].discard(dn[getname])
            ps.append(set([dn[getname]]))
    dp,yy,ban=[[False]*n],[0]*m,-1
    for i in ps[0]:
        dp[0][i]=True
    for i in range(1,m):
        dp.append([False]*n)
        for j in ps[i]:
            for k in range(n):
                if k!=j and dp[-2][k]==True:
                    dp[-1][j]=True
                    break
    if True not in dp[-1]:
        stdout.write("Impossible\n")
        continue
    for i in range(m-1,-1,-1):
        for j in range(n):
            if j!=ban and dp[i][j]:
                ban=j
                yy[i]=j
                break
    for i in range(m):
        stdout.write(names[yy[i]]+":"+text[i])