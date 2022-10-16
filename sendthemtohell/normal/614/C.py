from math import *
from sys import *
from decimal import *

def S(r1,r2):
    return acos(-1)*(r2-r1)

def geth(x0,y0,x1,y1,x2,y2):
    U1=x1*(y1-y2)+y1*(x2-x1)
    U2=x0*(x1-x2)+y0*(y1-y2)
    KEK1=y1-y2
    KEK2=x1-x2
    det1=U1*KEK1+U2*KEK2
    det2=U2*KEK1-U1*KEK2
    det=KEK1**2+KEK2**2
    return det1/det,det2/det

def diist(x0,y0,x1,y1):
    return sqrt((x0-x1)**2+(y0-y1)**2)

n,x0,y0=(int(z) for z in stdin.readline().split())
ma,mi=0,10**15
xp,yp=10**7,10**7
xf,yf=0,0
for i in range(n):
    xc,yc=(int(z) for z in stdin.readline().split())
    dist=(x0-xc)**2+(y0-yc)**2
    ma=max(dist,ma)
    mi=min(dist,mi)
    if xp<=10**6:
        xmid,ymid=geth(x0,y0,xc,yc,xp,yp)
        #print(xmid,ymid)
        if diist(xmid,ymid,xc,yc) + diist(xmid,ymid,xp,yp) <= diist(xc,yc,xp,yp):
            mi=min((xmid-x0)**2+(ymid-y0)**2,mi)
    else:
        xf,yf=xc,yc
    xp,yp=xc,yc
xmid,ymid=geth(x0,y0,xc,yc,xf,yf)
#print(xmid,ymid)
#print(xc,yc,xf,yf)
#print(diist(xmid,ymid,xc,yc)+diist(xmid,ymid,xf,yf),diist(xc,yc,xf,yf))
if diist(xmid,ymid,xc,yc)+diist(xmid,ymid,xf,yf)<=diist(xc,yc,xf,yf):
    #print("OK")
    mi=min((xmid-x0)**2+(ymid-y0)**2,mi)
#print(mi,ma)
print(S(mi,ma))