def isp(n):
        for i in range(2,n):
                if n%i==0: return False
        return True
n=int(input())
if n==2: print -1
else:
        p=[]
        now=2
        while len(p)<n:
                if isp(now): p.append(now)
                now+=1
        tmt=1
        for i in p: tmt*=i
        for i in p: print tmt/i