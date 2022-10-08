#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    int x;
    scanf("%d", &x);
    return x;
}
ll a[500009],b[500009],p[500009],f[500009];
ll n, m;
void upd(ll x, ll d){
    while(x <= m)
        f[x] += d,
        x += (x& -x);
}
ll cnt(ll x){
    ll ans = 0;
    while(x)
        ans += f[x],
        x -= (x&-x);
    return ans;
}
main(){
    cin >> n;
    for(ll i=1; i <= n; i++){
        a[i] = read();
    }
    for(ll i =1; i <= n; i++){
        p[i] = read();
    }
    cin >> m;
    for(ll i =1 ;i <= m; i++){
        b[i] = read();
    }
    ll j = 1;
    for(ll i = 1 ;i <= n; i++){
        if(j <= m && a[i] == b[j]) j++;
    }
    if(j <= m){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    upd(1, -1e16);
    for(ll i = 1; i <= n; i++){
        ll lo = 1, hi = m+1;
        while(lo < hi){
            ll mid = (lo + hi)/2;
            if(b[mid] < a[i])
                lo = mid + 1;
            else hi = mid;
        }
        if(lo == m + 1) continue;
        if(p[i] > 0) upd(lo, p[i]);
        if(a[i] == b[lo]) {
            ll y = cnt(lo);
            ll z = cnt(lo - 1);
            if(z + p[i] > y){
                ll d = z + p[i] - y;
                upd(lo, d);
                upd(lo + 1, -d);
            }
        }
    }
    ll ans = - cnt(m);
    for(ll i =1 ;i <= n; i++)
        ans += p[i];
    cout << ans << endl;

}