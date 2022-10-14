n=int(input())
skobs1=dict()
skobs2=dict()
ptav_cnt=0
for t in range(n):
    skob=input()
    fl=2
    opcnt=0
    clcnt=0
    opcnt2=0
    clcnt2=0
    for s in range(len(skob)):
        if skob[s]==')':
            clcnt+=1
        else:
            opcnt+=1
        if clcnt>opcnt:
            fl=1
    for s in range(len(skob)-1,-1,-1):
        if skob[s]==')':
            clcnt2+=1
        else:
            opcnt2+=1
        if clcnt2<opcnt2 and fl==1:
            fl=0
    if fl:
        if opcnt==clcnt:
            ptav_cnt+=1
        elif opcnt>clcnt:
            if opcnt-clcnt in skobs1:
                skobs1[opcnt-clcnt]+=1
            else:
                skobs1[opcnt - clcnt] = 1
        else:
            if clcnt-opcnt in skobs2:
                skobs2[clcnt - opcnt]+=1
            else:
                skobs2[clcnt - opcnt] = 1
ans=ptav_cnt//2
for t in skobs1:
    if t in skobs2:
        ans+=min(skobs1[t],skobs2[t])
print(ans)