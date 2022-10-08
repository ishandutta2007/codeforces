import sys
INF=10000
a=[[INF]*26 for _ in xrange(26)]
s=str(raw_input())
t=str(raw_input())
n=input()
for i in xrange(26):
    a[i][i]=0
for i in xrange(n):
    x,y,z=raw_input().split()
    x=ord(x)-97;y=ord(y)-97;z=int(z)
    a[x][y]=min(a[x][y],z)
for k in xrange(26):
    for i in xrange(26):
        for j in xrange(26):
            a[i][j]=min(a[i][j],a[i][k]+a[k][j])
m=len(s)
if m!=len(t):
    print -1
    sys.exit()
S=0;T=""
for i in xrange(m):
    w=INF;cs=ord(s[i])-97;ct=ord(t[i])-97
    for j in xrange(26):
        if a[cs][j]+a[ct][j]<w:
            w=a[cs][j]+a[ct][j]
            u=chr(j+97)
    if w==INF:
        print -1
        sys.exit()
    S+=w;T+=u
print S
print T