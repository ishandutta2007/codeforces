#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    vector<ll> sum(n+1,0);
    for (int i=0;i<n;++i) sum[i+1]=sum[i]+a[i];
    vector<ll> compress(n+1),A(n+1);
    for (int i=0;i<n+1;++i) compress[i]=sum[i];
    sort(compress.begin(),compress.end());
    compress.erase(unique(compress.begin(),compress.end()),compress.end());
    for (int i=0;i<n+1;++i) A[i]=lower_bound(compress.begin(),compress.end(),sum[i])-compress.begin();
    int m=compress.size();
    vector<vector<int>> cnt(m);
    for (int i=0;i<n+1;++i) cnt[A[i]].emplace_back(i);
    for (int i=0;i<m;++i) cnt[i].emplace_back(n+1);
    ll ans=0;
    int most=n+1;
    for (int i=n;i>=0;--i){
        int r=*upper_bound(cnt[A[i]].begin(),cnt[A[i]].end(),i);
        most=min(most,r);
        ans+=(ll)(most-i-1);
    }
    cout << ans << '\n';
}