#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,A,B;
vector<int> v;
ll solve(ll l,ll r)
{
    ll cnt=upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
    if(cnt==0) return A;
    if(l==r) return B*cnt;
    ll mid=(l+r)/2;
    ll res=solve(l,mid)+solve(mid+1,r);
    return min(res,B*cnt*(r-l+1));
}
int main()
{
    scanf("%lld%lld%lld%lld",&n,&k,&A,&B);
    for(ll i=0;i<k;i++)
    {
        ll x;
        scanf("%lld",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    printf("%lld\n",solve(1,(1<<n)));
    return 0;
}