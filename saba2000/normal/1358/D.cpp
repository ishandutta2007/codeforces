#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500009],S[400009],s[400009];
ll ans = 0;
void upd(ll x){
    ans = max(ans, x);
}
ll x,n;
void solve(ll l, ll r){
    if(l == r){
        if(a[l] < x) return;
        ll L = a[l] - x + 1, R = a[l];
        upd((R - L + 1) * (R + L)/2);
        return;
    }
    ll D = x - (S[r - 1] - S[l]);
    if(D < 0 || D > a[l] + a[r]) return;
    if(a[l] >= D) {
        ll L = a[l] - D + 1, R = a[l];
        upd(s[r-1] - s[l] + (R - L + 1) * (R + L)/2);
        return;
    }
    if(a[r] >= D){
        upd(s[r-1] - s[l] + D * (D + 1)/ 2);
        return;
    }
    
    D = D - a[r];
    ll L = a[l] - D + 1, R = a[l];
    upd(s[r-1] - s[l] + (R - L + 1) * (R + L)/2 + a[r] * (a[r] + 1)/2);

}
main(){
    cin >> n>>x;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i] * (a[i] + 1) / 2;
        S[i] = S[i-1] + a[i];

    }
    ll l = 1,r  = -1;
    for(ll i = 1; i <= n; i++){
        a[i + n] = a[i];
        s[i+n] = s[i + n - 1] + a[i] * (a[i] + 1) / 2;
        S[i+n] = S[i + n - 1] + a[i];
        if(S[i] >= x && r == -1) r = i;
    }

    n = 2 * n;
    vector<pair<ll,ll> > v;
    for(ll i = 1; i <= n; i++){
        v.push_back({S[i-1] + 1,i});
        if(i > r) v.push_back({S[i-1] + 1 - x + 1, -i});
    }
    sort(v.begin(),v.end());
    solve(l,r);
    for(ll i = 0; i < v.size() ;i++){
        ll x = v[i].second;
        if(x < 0) r = -x;
        else l = x;
        solve(l, r);
    }
    cout<<ans<<endl;
}