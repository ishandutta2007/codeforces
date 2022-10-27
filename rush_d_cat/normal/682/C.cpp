#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 ll;
vector<ll> vec[100000+10];
vector<ll> dis[100000+10];
ll a[100000+10];
bool used[100000+10];
ll res=0;
ll solve(ll i)
{
    ll ans=1;
    used[i]=1;
    for(ll j=0;j<vec[i].size();j++)
    {
        if(!used[vec[i][j]]) ans+=solve(vec[i][j]);
    }
    return ans;
}
void dfs(ll i,ll m)
{
    if(used[i]) return;
    used[i]=1;
    if(m>a[i])//d is too big
    {
        res+=solve(i);
        return;
    }
    for(ll j=0;j<vec[i].size();j++)
    {
        if(!used[vec[i][j]]){
            if(m>=0)
            {
                dfs(vec[i][j],m+dis[i][j]);
            }else{
                dfs(vec[i][j],dis[i][j]);
            }
        }
    }
}
int main()
{
    ll n;cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++) used[i]=0;
    for(ll i=2;i<=n;i++)
    {
        ll x,y;cin>>x>>y;
        vec[i].push_back(x);
        vec[x].push_back(i);
        dis[i].push_back(y);
        dis[x].push_back(y);
    }
    dfs(1,0);
    cout<<res<<endl;
    return 0;
}