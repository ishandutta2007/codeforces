#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200009],b[200009];
ll L[200009],R[200009];
ll D[200009];
ll mx[200009];
ll f[200009];
ll mod = 998244353;
main(){
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    for(ll i =1; i <= m; i++)
        cin >> b[i];
    for(ll i = n; i >= 1; i--){
        if(a[i] < b[1]){
            cout << 0 << endl;
            return 0;

        }
        ll lo = 1, hi = m;
        while(lo < hi){
            ll mid = (lo + hi+1)/2;
            if(a[i] >= b[mid]) lo = mid;
            else hi = mid - 1;
        }
        if(a[i] == b[lo] && f[lo] == 0) {
            f[lo] = 1;
            D[i] = lo;
        }
        mx[i] = lo;
    }
    for(ll i = n-1; i >= 1; i--){
        mx[i] = min(mx[i], mx[i+1]);
    }
    for(ll i = 1; i <= n; i++){
        if(D[i] && D[i] != mx[i]) {
            cout << 0 <<endl;
            return 0;
        }
        if(i < n && mx[i+1] > mx[i]+1){
            cout<<0<<endl;
            return 0;
        }
    }
    for(ll i = 1; i <= m; i++){
        if(f[i] == 0){
            cout<<0<<endl;
            return 0;
        }
    }
    if(mx[n] != m){
        cout <<0<<endl;
        return 0;
    }
    for(ll i = 1; i <= n; i++){
        if(mx[i] > mx[i-1]) L[mx[i]] = i;
        if(mx[i] == D[i]) R[mx[i]] = i;
    }
    ll ans =  1;
    for(ll i = 2; i <= m; i++){
        ans = ans * (R[i]- L[i] + 1) % mod;
    }
    cout<<ans<<endl;

}
/*



*/