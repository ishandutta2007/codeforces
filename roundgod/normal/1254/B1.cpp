#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
vector<int> v;
ll get_res()
{
    ll ans=0;
    int sz=(int)v.size();
    for(int i=0;i<sz/2;i++) ans+=v[sz-1-i]-v[i];
    return ans;
}
ll get_ans(int d)
{
    v.clear();
    if(d==1) return INF;
    int cnt=0;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]) {cnt++; v.push_back(i);}
        if(cnt==d)
        {
            ans+=get_res(); cnt=0;
            v.clear();
        }
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum==1) {puts("-1"); return 0;}
    ll ans=INF;
    for(int i=1;i*i<=sum;i++)
    {
        if(sum%i) continue;
        ans=min(ans,get_ans(i));
        ans=min(ans,get_ans(sum/i));
    }
    printf("%lld\n",ans);
    return 0;
}