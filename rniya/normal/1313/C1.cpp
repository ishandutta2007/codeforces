#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> m(n),ans(n);
    for (int i=0;i<n;++i) cin >> m[i];
    ll M=0; int center;
    for (int i=0;i<n;++i){
        ll cnt=m[i],pre=m[i];
        for (int j=i+1;j<n;++j){
            cnt+=min(m[j],pre);
            pre=min(m[j],pre);
        }
        pre=m[i];
        for (int j=i-1;j>=0;--j){
            cnt+=min(m[j],pre);
            pre=min(m[j],pre);
        }
        if (M<cnt) M=cnt,center=i;
    }
    ans[center]=m[center];
    for (int i=center+1;i<n;++i) ans[i]=min(ans[i-1],m[i]);
    for (int i=center-1;i>=0;--i) ans[i]=min(ans[i+1],m[i]);
    for (int i=0;i<n;++i) cout << ans[i] << (i!=n-1?' ':'\n');
}