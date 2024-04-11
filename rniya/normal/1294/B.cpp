#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        vector<pair<int,int>> pos;
        pos.emplace_back(0,0);
        for (int i=0;i<n;++i){
            int x,y; cin >> x >> y;
            pos.emplace_back(x,y);
        }
        sort(pos.begin(),pos.end());
        int ok=1;
        string ans="";
        for (int i=1;i<=n;++i){
            for (int j=0;j<pos[i].first-pos[i-1].first;++j)
                ans+='R';
            if (pos[i].second<pos[i-1].second){ok=0; break;}
            for (int j=0;j<pos[i].second-pos[i-1].second;++j)
                ans+='U';
        }
        cout << (ok?"YES":"NO") << '\n';
        if (ok) cout << ans << '\n';
    }
}