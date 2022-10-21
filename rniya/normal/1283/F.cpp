#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n-1);
    for (int i=0;i<n-1;++i) cin >> a[i];
    set<int> alr;
    int now=0,ok=n;
    vector<vector<int>> G(n+1);
    vector<int> used(n+1,0);
    for (int i=0;i<n-1;++i){
        if (!alr.count(a[i])){
            G[now].emplace_back(a[i]); used[a[i]]=1;
            alr.emplace(a[i]); now=a[i];
        }
        else {
            while(0<=ok&&used[ok]) --ok;
            G[now].emplace_back(ok); used[ok]=1;
            alr.emplace(ok); now=a[i];
        }
    }
    for (int i=1;i<=n;++i) if (!used[i])
        G[a[n-2]].emplace_back(i);
    cout << a[0] << '\n';
    for (int v=1;v<=n;++v){
        for (int u:G[v]) cout << v << ' ' << u << '\n';
    }
}