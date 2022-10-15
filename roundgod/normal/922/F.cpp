#include<bits/stdc++.h>
#define MAXN 300005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime[MAXN],d[MAXN];
bool is_prime[MAXN];
bool remov[MAXN];
vector<P> ans;
bool cmp(P x,P y)
{
    if(x.F!=y.F) return x.F>y.F;
    return x.S<y.S;
}
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
        for(int j=2*i;j<=n;j+=i) d[j]++;
    }
    return p;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=2;i<MAXN;i++)
        d[i]=1;
    d[1]=0;
    int p=sieve(n);
    int sum=0,t=-1;
    for(int i=1;i<=n;i++)
    {
        sum+=d[i];
        if(sum>=k) {t=i; break;}
    }
    if(t==-1)
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    for(int i=t/2+1;i<=t;i++)
        ans.push_back(P(d[i],i));
    sort(ans.begin(),ans.end(),cmp);
    int dif=sum-k;
    memset(remov,false,sizeof(remov));
    int res=t;
    for(int i=0;i<ans.size();i++)
    {
        if(dif==0) break;
        if(ans[i].F<=dif)
        {
            remov[ans[i].S]=true;
            res--;
            dif-=ans[i].F;
        }
    }
    assert(dif==0);
    printf("%d\n",res);
    for(int i=1;i<=t;i++)
        if(!remov[i]) printf("%d ",i);
    return 0;
}