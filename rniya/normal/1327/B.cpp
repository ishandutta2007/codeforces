#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        vector<vector<int>> G(n);
        for (int i=0;i<n;++i){
            int k; cin >> k;
            for (int j=0;j<k;++j){
                int g; cin >> g;
                G[i].emplace_back(--g);
            }
        }
        vector<int> used(n,0);
        int unused=-1,king;
        for (int v=0;v<n;++v){
            int ok=0;
            for (int u:G[v]) if (!used[u]){
                used[u]=1; ok=1; break;
            }
            if (!ok) unused=v;
        }
        if (unused==-1){cout << "OPTIMAL" << '\n'; continue;}
        cout << "IMPROVE" << '\n';
        for (int i=0;i<n;++i) if (!used[i]) king=i;
        cout << unused+1 << ' ' << king+1 << '\n';
    }
}