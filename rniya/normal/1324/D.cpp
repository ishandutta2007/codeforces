#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n),b(n);
    for (int i=0;i<n;++i) cin >> a[i];
    for (int i=0;i<n;++i) cin >> b[i];
    for (int i=0;i<n;++i) a[i]-=b[i];
    sort(a.begin(),a.end());
    ll ans=0;
    for (int i=0;i<n;++i){
        ans+=a.end()-upper_bound(a.begin(),a.end(),-a[i]);
        if (0<a[i]) --ans;
    }
    cout << ans/2 << '\n';
}