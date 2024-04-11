#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll> b={0,2,3,1};

pair<ll,ll> dfs(ll v){
    if (v==0) return {4,8};
    if (v==1) return {5,10};
    if (v==2) return {6,11};
    if (v==3) return {7,9};
    pair<ll,ll> p=dfs(v/4-1);
    p.first<<=2LL; p.second<<=2LL;
    p.first|=v%4; p.second|=b[v%4];
    return p;
}

void solve(){
    if (n<3){
        cout << n+1 << '\n';
        return;
    }
    ll g=n/3-1;
    pair<ll,ll> p=dfs(g);
    vector<ll> ans={p.first,p.second,(p.first^p.second)};
    cout << ans[n%3] << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n; --n;
        solve();
    }
}