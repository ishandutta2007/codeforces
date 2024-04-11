#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    vector<ll> a(n),left(n,0),right(n,0);
    for (int i=0;i<n;++i) cin >> a[i];
    sort(a.begin(),a.end());
    int j;
    for (int i=0;i<n;i=j){
        j=i;
        while(j<n&&a[j]==a[i]) ++j;
        if (k<=j-i){cout << 0 << '\n'; return 0;}
    }
    for (int i=1;i<n;++i){
        left[i]=left[i-1]+i*(a[i]-a[i-1]);
        right[n-1-i]=right[n-i]+i*(a[n-i]-a[n-1-i]);
    }
    ll ans=(ll)1e18;
    for (int i=0;i<n;++i){
        if (k<=i+1) ans=min(ans,left[i]-(i+1-k));
        if (k<=n-i) ans=min(ans,right[i]-(n-i-k));
    }
    for (int i=0;i<n;++i) ans=min(ans,left[i]+right[i]-(n-k));
    cout << ans << '\n';
}