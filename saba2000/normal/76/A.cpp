#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, G, S, X, A , B;
multiset < ll > E;
vector<ll> v[209],l[209];
ll f[209];
bool dfs(ll a, ll b){
    f[a] = 1;
    if(a == b) return 1;
    bool F = 0;
    for(ll i= 0; i < v[a].size(); i++){
        if(f[v[a][i]]) continue;
        if(dfs(v[a][i],b)) {
            if(X < l[a][i]){
                X = max(X, l[a][i]);
                A = v[a][i];
                B = a;
            }
            F = 1;
        }
    }
    return F;
}
ll adddd(ll a , ll b, ll w){
    for(ll i = 1; i <= n; i++)
        f[i] = 0;
    X= 0;
    if(!dfs(a, b)){

        v[a].push_back(b);
        v[b].push_back(a);
        l[b].push_back(w);
        l[a].push_back(w);
        E.insert(w);
    }
    else{
        if(w < X){
            E.erase(E.find(X));
            for(ll i = 0; i < v[A].size(); i++){
                if(v[A][i] == B){
                    swap(v[A][i], v[A].back());
                    swap(l[A][i], l[A].back());
                    v[A].pop_back();
                    l[A].pop_back();
                    break;
                }
            }
            for(ll i = 0; i < v[B].size(); i++){
                if(v[B][i] == A){
                    swap(v[B][i], v[B].back());
                    swap(l[B][i], l[B].back());
                    v[B].pop_back();
                    l[B].pop_back();
                    break;
                }
            }
            v[a].push_back(b);
            v[b].push_back(a);
            l[b].push_back(w);
            l[a].push_back(w);
            E.insert(w);
        }
    }
    if(E.size() != n - 1) return -1;
    else return (*(--E.end()));
}
main(){
    cin >> n >> m >> G >> S;
    vector<pair<pair<ll,ll>,pair<ll,ll> > > v;
    for(ll i = 0; i < m; i++){
        ll a,b,g,s;
        cin >> a >> b >> g >> s;
        v.push_back({{g,s},{a,b}});
    }
    sort(v.begin(),v.end());
    ll ans = -1;
    for(ll i = 0; i < v.size(); i++){
        ll g = v[i].first.first, s = v[i].first.second, a = v[i].second.first, b = v[i].second.second;
        ll X = adddd(a,b,s);
        if(X != -1) {
            if (ans == -1) ans = G * g + S * X;
            else ans = min(ans, G * g + S * X);
        }
    }
    cout << ans << endl;
}