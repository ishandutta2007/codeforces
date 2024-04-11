def clear(a):
    s=""
    for i in a:
        if(i!='_' and i!=';' and i!='-'):
            s+=i
    return s.lower()

a={}
for i in range(3):
    a[i]=clear(raw_input());
r={}
for i in range(27):
    r[i]=None
for i in range(3):
    for j in range(3):
        if i!=j:
            for k in range(3):
                if i!=k:
                    if j!=k:
                        r[9*i+3*j+k]=a[i]+a[j]+a[k];
n=input()
for i in range(n):
    ans=clear(raw_input())
    for i in range(27):
        if(r[i] is not None and r[i]==ans):
            print "ACC"
            break
    else:
        print "WA"