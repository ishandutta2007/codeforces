#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define MAXM 1000005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,e,n,a[MAXN];
int prime[MAXM];
bool is_prime[MAXM];
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
int cnt[MAXN];
void solve(int id)
{
    vector<int> v;
    for(int i=id;i<=n;i+=e)
    {
        if(is_prime[a[i]]) v.push_back(1);
        else if(a[i]==1) v.push_back(0);
        else v.push_back(2);
    }
    for(int i=0;i<=2*(int)v.size();i++) cnt[i]=0;
    cnt[0]=1;
    int s=0;
    for(auto x:v)
    {
        s+=x;
        if(s) ans+=cnt[s-1];
        if(x==1) ans--;
        cnt[s]++;
    }
}
int main()
{
    sieve(1000000);
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d",&n,&e);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=e;i++) solve(i);
        printf("%lld\n",ans);
    }
    return 0;
}