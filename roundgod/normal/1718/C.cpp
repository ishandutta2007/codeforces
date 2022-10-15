#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q,k,a[MAXN];
int prime[MAXN],sp[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; sp[i]=i;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            sp[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
vector<int> fact;
void factorize(int v)
{
    fact.clear();
    while(v>1)
    {
        int p=sp[v];
        fact.push_back(p);
        while(v%p==0) v/=p;
    }
}
vector<vector<int> > sum;
vector<int> maxi;
int main()
{
    int p=sieve(200000);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        factorize(n); fact.push_back(n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(auto &x:fact) x=n/x;
        sort(fact.begin(),fact.end()); fact.erase(unique(fact.begin(),fact.end()),fact.end());
        if(fact.back()==n) fact.pop_back();
        maxi.clear(); sum.clear();
        int sz=(int)fact.size();
        sum.resize(sz); 
        multiset<ll> maxi;
        for(int i=0;i<sz;i++)
        {
            sum[i].resize(fact[i]);
            for(int j=0;j<fact[i];j++)
            {
                for(int k=j;k<n;k+=fact[i]) sum[i][j]+=a[k];
                maxi.insert(1LL*sum[i][j]*fact[i]);
            }
        }
        printf("%lld\n",*(--maxi.end()));
        for(int i=0;i<q;i++)
        {
            int p,x;
            scanf("%d%d",&p,&x);
            p--;
            int d=x-a[p];
            for(int j=0;j<sz;j++)
            {
                int mod=p%fact[j];
                maxi.erase(maxi.find(1LL*sum[j][mod]*fact[j]));
                sum[j][mod]+=d;
                maxi.insert(1LL*sum[j][mod]*fact[j]);
            }
            a[p]=x;
            printf("%lld\n",*(--maxi.end()));
        }
    }
    return 0;
}