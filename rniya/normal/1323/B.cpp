#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> divisor(ll n){
    vector<ll> res;
    for (ll i=1;i*i<=n;++i) if (n%i==0){
        res.emplace_back(i);
        if (i!=n/i) res.emplace_back(n/i);
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,k; cin >> n >> m >> k;
    vector<int> a(n),b(m);
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<m;++i) cin >> b[i];
    vector<ll> cand=divisor(k),imos1(n+2,0),imos2(m+2,0);
    set<int> s1,s2;
    for (int i=0;i<n;++i) if (!a[i]) s1.emplace(i);
    s1.emplace(n);
    for (int i=0;i<n;++i){
        int t=*s1.lower_bound(i);
        ++imos1[0]; --imos1[t-i+1];
    }
    for (int i=0;i<n;++i) imos1[i+1]+=imos1[i];
    for (int i=0;i<m;++i) if (!b[i]) s2.emplace(i);
    s2.emplace(m);
    for (int i=0;i<m;++i){
        int t=*s2.lower_bound(i);
        ++imos2[0]; --imos2[t-i+1];
    }
    for (int i=0;i<m;++i) imos2[i+1]+=imos2[i];
    ll ans=0;
    for (int x:cand){
        if (n<x||m<k/x) continue;
        ans+=imos1[x]*imos2[k/x];
    }
    cout << ans << '\n';
}