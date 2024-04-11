def pwm(a,pw,mod):
    ans = 1
    while pw:
        if pw&1:
            ans*=a
            ans%=mod
        a*=a
        pw>>=1
        a%=mod
    return ans

def precalc(mod):
    rfact[0]=1
    for i in range(1,5432):
        fact[i]=(fact[i-1]*i)%mod
        rfact[i]=pwm(fact[i],mod-2,mod)

def cnk(n,k,mod):
    return (fact[n]*rfact[k]*rfact[n-k])%mod
    
def calc(a,b,mod):
    ans = 0
    for k in range(min(a,b)+1):
        ans+=(cnk(a,k,mod)*cnk(b,k,mod)*fact[k])
        #print(a,b,cnk(a,k,mod),cnk(b,k,mod))
        ans%=mod
    return ans

fact = [1]*5432
rfact = [0]*5432
mod = 998244353
precalc(mod)
a,b,c = (int(z) for z in input().split())
res=calc(a,b,mod)*calc(a,c,mod)*calc(b,c,mod)
res%=mod
print(res)