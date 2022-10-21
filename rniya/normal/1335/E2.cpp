#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=2e5+10,MAX_A=205;

int n;
int a[MAX_N];
vector<vector<int>> G(MAX_A);

void solve(){
    for (int i=0;i<MAX_A;++i) G[i].clear();
    for (int i=0;i<n;++i){
        G[a[i]].emplace_back(i);
    }
    int ans=0;
    vector<int> cnt(MAX_A,0);
    for (int i=n-1;i>=0;--i){
        int l=G[a[i]][cnt[a[i]]];
        if (i<=l) continue;
        int sum=0;
        for (int j=0;j<MAX_A;++j){
            sum=max(sum,(int)(lower_bound(G[j].begin(),G[j].end(),i)-upper_bound(G[j].begin(),G[j].end(),l)));
        }
        ans=max(ans,sum+(cnt[a[i]]+1)*2);
        ++cnt[a[i]];
    }
    for (int i=0;i<MAX_A;++i) ans=max(ans,(int)G[i].size());
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