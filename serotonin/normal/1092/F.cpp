#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5;

ll done[sz];
vector <ll> a[sz];
ll d[sz],s[sz],total=0,ans,sum=0;

ll dfs(ll n, ll c)
{
    if(done[n]) return 0;
    done[n]=1;

    ll x=d[n];
    for(ll i=0; i<a[n].size(); i++) {
        x+=dfs(a[n][i], c+1);
    }
    total+=c*d[n];
    return s[n]=x;
}

void dfs2(ll n, ll c)
{
    if(done[n]) return;
    done[n]=1;
    ans=max(ans,c);

    for(ll i=0; i<a[n].size(); i++) {
        dfs2(a[n][i], c+sum-2*s[a[n][i]]);
    }
    //printf("%lld %lld\n", n, c);
}

int main()
{
    ll n,i,j,k=0;
    cin >> n;
    for(i=1; i<=n; i++) {
        scanf("%I64d", &d[i]);
        sum+=d[i];
    }
    for(i=0; i<n-1; i++) {
        ll w,v;
        scanf("%lld %lld", &w, &v);
        a[w].push_back(v);
        a[v].push_back(w);
    }
    dfs(1,0);
    memset(done, 0, sizeof done);
    dfs2(1, total);
    cout << ans << endl;
}