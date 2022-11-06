#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=4e5,INF=1e17;

vector <ll> tree[sz];
ll v[sz],ans[sz];

void dfs(ll n, ll c)
{
    if(v[n]==-1) {
        ll mi=INF;
        for(ll i=0; i<tree[n].size(); i++) {
            mi=min(mi, v[tree[n][i]]-c);
        }
        if(mi==INF) mi=0;
        ans[n]=mi;
    }
    else ans[n]=v[n]-c;

    for(ll i=0; i<tree[n].size(); i++) dfs(tree[n][i], c+ans[n]);
}

int main()
{
    ll n,i,j;
    cin >> n;
    for(i=2; i<=n; i++) {
        scanf("%lld", &j);
        tree[j].push_back(i);
    }
    for(i=1; i<=n; i++) {
        ans[i]=-1;
        scanf("%lld", &v[i]);
    }
    dfs(1, 0);
    ll fin=0;
    for(i=1; i<=n; i++) {
        if(ans[i]<0) break;
        fin+=ans[i];
    }
    if(i>n) printf("%lld\n", fin);
    else printf("-1\n");
}