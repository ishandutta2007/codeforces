from math import *

class sqrt_decomp:
    def _init_(self,val):
        self.values=val
        self.blockl=int(sqrt(len(val)))
        self.noblocks=int(ceil(len(val)/self.blockl))
        self.plusv=[0]*self.noblocks
        self.sumbl=[0]*self.noblocks
        for i in range(self.noblocks):
            self.sumbl=sum(val[i*self.blockl:max(len(val),(i+1)*self.blockl)])

def maximize(n,X,l):
    if l==0:
        return 0
    cur=ans[l-1]
    X-=cur**3
    while X+(cur+1)**3<=n:
        cur+=1
        #print("again",cur,X,X+cur**3,n)
    Xy=cur**3
    Xy+=maximize(min(n-Xy,(cur+1)**3-Xy-1),X,l-1)
    ans[l-1]=cur
    return Xy
    
    

n=int(input())
c=1
ans=[]
X=0
while X+c**3<=n:
    while X<(c+1)**3-c**3 and X+c**3<=n:
        ans+=[c]
        X+=c**3        
        #print(c,X,ans)
    c+=1
    #print(c,c**3,X,n,"rofl")
X=maximize(n,X,len(ans))
print(len(ans),X)
#print(ans)