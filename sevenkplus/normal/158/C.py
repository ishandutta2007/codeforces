a=[]
n=input()
for nn in xrange(n):
    s=raw_input()
    if s=="pwd":
        al=len(a)
        t=""
        for i in xrange(al):
            t+="/"+a[i]
        t+="/"
        print t
    else:
        s=s.split(" ")[1]
        t=s.split("/")
        tl=len(t)
        for i in xrange(tl):
            if t[i]=="":
                a=[]
            elif t[i]=="..":
                a.pop()
            else:
                a.append(t[i])