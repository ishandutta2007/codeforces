#include<bits/stdc++.h>
#define MAXN 5005
#define MAXP 670
#define MAXM 4000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int prime[MAXN];
bool is_prime[MAXN];
int cnt[MAXN],cntp[MAXP];
int tot=1;
vector<P> fact[MAXN];
ll ans;
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    int p=sieve(5000);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    ll res=0;
    ans=INF;
    for(int i=1;i<=5000;i++)
    {
        int c;
        for(int j=0;prime[j]<=i&&j<p;j++)
        {
            int c=0,x=i;
            while(x)
            {
                c+=x/prime[j];
                x/=prime[j];
            }
            if(c) fact[i].push_back(P(j,c));
            res+=1LL*c*cnt[i];
        }
    }
    int cur=1;
    while(true)
    {
        memset(cntp,0,sizeof(cntp));
        int maxi=-1,id=-1;
        for(int i=2;i<=5000;i++)
        {
            if(cnt[i]&&fact[i].size())
            {
                P &p=fact[i].back();
                cntp[p.F]+=cnt[i];
            }
        }
        for(int i=0;i<p;i++)
        {
            if(cntp[i]>maxi)
            {
                maxi=cntp[i];
                id=i;
            }
        }
        if(maxi*2<=n) break;
        res-=(maxi*2-n);
        for(int i=2;i<=5000;i++)
        {
            if(cnt[i])
            {
                if(!fact[i].size()) {cnt[i]=0; break;}
                P &p=fact[i].back();
                if(p.F!=id) cnt[i]=0; else 
                {
                    p.S--;
                    while(fact[i].size()&&fact[i].back().S==0) fact[i].pop_back();
                }
            }
        }
    }
    printf("%lld\n",res);
    return 0;
}