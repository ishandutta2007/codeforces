from sys import *



res=set()
for i in range(10):
    print(str(i)*4)
    a,b=(int(z) for z in input().split())
    if a+b!=0:
        res.add(str(i))
for i in res:
    rr=set()
    for j in res:
        rr.add(j)
    rr.remove(i)
    for j in rr:
        r=set()
        for k in rr:
            r.add(k)
        r.remove(j)
        for k in r:
            re=set()
            for h in r:
                re.add(h)
            re.remove(k)
            for h in re:
                print(i+j+k+h)
                a,b=(int(z) for z in input().split())
                if a==4:
                    exit(0)