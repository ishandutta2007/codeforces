#include <bits/stdc++.h>
using namespace std;
int mod=1000000007;
long long P(long long a,long long b)
{
    if (b==0)return 1;
    long long x = P(a,b/2);
    x=(x*x)%mod;
    if (b%2)x=(x*a)%mod;
    return x;
}
long long inv(long long x)
{
    return P(x,mod-2);
}
long long F[1000000];
long long C(long long n,long long k)
{
    if (k>n)return 0;
    if (k==0)return 1;
    if (k==1)return n;
    long long A = F[n];
    long long B = inv((F[n-k]*F[k])%mod);
    return (A*B)%mod;
}
long long t[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    long long T;
    cin>>n>>T;
    F[0]=1;
    for (int i=1;i<=n;i++)
        F[i]=(F[i-1]*i)%mod;
    long long N = 1;
    long long K = 1;
    long long sum = 2;
    long long cur=0;
    long long ret=0;
    for (int i=1;i<=n;i++)
    {
        cin>>t[i];
        cur+=t[i];
        if (cur+i<=T)
        {
            ret=(ret+1)%mod;
            continue;
        }
        if (cur>T)
            break;
        long long top = i;
        long long bot = min(i+0LL,T-cur);
        while(N<top)
        {
            if (K==N)
            {
                sum=(sum-C(N,K)+mod)%mod;
                K--;
            }
            sum = (sum*2 + C(N,K+1))%mod;
            N++;
            K++;
        }
        while(K>bot)
        {
            sum = (sum-C(N,K)+mod)%mod;
            K--;
        }
        ret += (inv(P(2,i))*sum)%mod;
        ret %= mod;
    }
    cout<<ret<<endl;
}