#include <bits/stdc++.h>
using namespace std;
const int MAX_N=2e5+10;

int n;
int a[MAX_N];

void solve(){
    vector<int> cnt(n,0);
    for (int i=0;i<n;++i) ++cnt[a[i]];
    int d=0;
    for (int i=0;i<n;++i) d+=(0<cnt[i]);
    int ans=0;
    for (int i=0;i<n;++i){
        ans=max(ans,min(d-1,cnt[i]));
        ans=max(ans,min(d,cnt[i]-1));
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n;
        for (int i=0;i<n;++i) cin >> a[i],--a[i];
        solve();
    }
}