#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<ll> l(m);
    for (int i=0;i<m;++i) cin >> l[i];
    vector<ll> sum(m+1,0);
    for (int i=m-1;i>=0;--i) sum[i]=sum[i+1]+l[i];
    if (sum[0]<n){cout << -1 << '\n'; return 0;}
    vector<ll> ans(m);
    ll pref=-1,preb=-1;
    for (int i=0;i<m;++i){
        int nxt=max(pref+1,n-sum[i+1]-l[i]);
        if (preb+1<nxt){cout << -1 << '\n'; return 0;}
        ans[i]=nxt; pref=nxt; preb=pref+l[i]-1;
    }
    for (int i=0;i<m;++i) if (n<=ans[i]+l[i]-1){
        cout << -1 << '\n'; return 0;
    }
    for (int i=0;i<m;++i) cout << ans[i]+1 << (i!=m-1?' ':'\n');
}