#include <bits/stdc++.h>
using namespace std;
const int MAX_N=2e5+10;

int t,n,ok,m;
int a[MAX_N],cnt[MAX_N];
vector<pair<int,int>> ans;

void solve(){
    for (int i=0;i<n;++i) cnt[i]=0;
    for (int i=0;i<n;++i) ++cnt[a[i]];
    ok=1,m=-1;
    for (int i=0;i<n;++i){
        if (2<cnt[i]||(i&&cnt[i-1]<cnt[i])) ok=0;
        if (m==-1&&cnt[i]<2) m=i;
    }
    if (!ok){cout << 0 << '\n'; return;}
    ans.clear();
    ok=1;
    for (int i=0;i<n;++i) cnt[i]=0;
    for (int i=0;i<m;++i) ++cnt[a[i]];
    for (int i=0;i<m;++i) if (cnt[i]!=1) ok=0;
    for (int i=0;i<n;++i) cnt[i]=0;
    for (int i=m;i<n;++i) ++cnt[a[i]];
    for (int i=0;i<n-m;++i) if (cnt[i]!=1) ok=0;
    if (ok) ans.emplace_back(m,n-m);
    ok=1;
    for (int i=0;i<n;++i) cnt[i]=0;
    for (int i=0;i<m;++i) ++cnt[a[n-1-i]];
    for (int i=0;i<m;++i) if (cnt[i]!=1) ok=0;
    for (int i=0;i<n;++i) cnt[i]=0;
    for (int i=m;i<n;++i) ++cnt[a[n-1-i]];
    for (int i=0;i<n-m;++i) if (cnt[i]!=1) ok=0;
    if (ok&&n-m!=m) ans.emplace_back(n-m,m);
    cout << ans.size() << '\n';
    for (auto p:ans) cout << p.first << ' ' << p.second << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    for (;t--;){
        cin >> n;
        for (int i=0;i<n;++i) cin >> a[i],--a[i];
        solve();
    }
}