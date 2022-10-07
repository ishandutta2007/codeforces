#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> v[100009];
ll ans[100009];
int n;
ll sz[100009];
vector<vector<int> > g;

void dfs(ll x, ll p){
    sz[x] = 1;
    for(ll y : v[x]){
        if(y == p) continue;
        dfs(y, x);
        sz[x] += sz[y];
    }
}
int fc(ll x, ll p){
    for(ll y : v[x]){
        if(y == p) continue;
        if(sz[y] >= n/2)
            return fc(y, x);
    }
    return x;
}
void dfs2(ll x, ll p){
    g.back().push_back(x);
    for(ll y : v[x]){
        if(y == p) continue;
        dfs2(y, x);
    }
}
main(){
    cin >> n;
    for(ll i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ll sum = 0;
    dfs(1, 0);

    for(int i = 2; i <= n; i++)
        sum += 2 * min(sz[i], n - sz[i]);

    int u = fc(1, 0);
    for(int w : v[u]){
        g.push_back({});
        dfs2(w, u);
    }
    g.push_back({u});
    priority_queue<pair<int,int> > q;
    for(int i = 0; i < g.size(); i++){
        q.push({g[i].size(), i});
    }
    int cnt = 0;
    while(cnt < n - 3){
        int u = q.top().second; q.pop();
        int w = q.top().second; q.pop();
        int x = g[u].back(); g[u].pop_back();
        int y = g[w].back(); g[w].pop_back();
        ans[x] = y;
        ans[y] = x;
        q.push({g[u].size(), u});
        q.push({g[w].size(), w});
        cnt+=2;
    }
    vector<int> rem;
    for(int i = 1; i <= n; i++)
        if(!ans[i]) rem.push_back(i);
    for(int i= 0 ;i < rem.size(); i++)
        ans[rem[i]] = rem[(i+1)%rem.size()];
    cout<<sum<<endl;
    for(int i = 1; i <= n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}