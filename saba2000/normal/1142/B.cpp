#include<bits/stdc++.h>
using namespace std;
const int N = 200009;
int a[N], p[N], f[N], nextt[N][20], g[N];

main(){
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        scanf("%d", &p[i]);
        f[p[i]] = i;
    }
    for(int i = 1; i <= m; i++){
        scanf("%d", &a[i]);
        a[i] = f[a[i]] - 1;
    }
    for(int i = m; i >= 1; i--){
        g[a[i]] = i;
        nextt[i][0] = g[(a[i] + 1) % n];
    }
    for(int i = 1; i <= 18; i++){
        for(int j = 0; j <= m; j++){
            nextt[j][i] = nextt[nextt[j][i-1]][i-1];
        }
    }
    vector<pair<int,int> > v;
    for(int i = 1; i <= m; i++){
        int x = i;
        for(int j = 18; j >= 0; j--){
            if((n-1) & (1 << j)) x = nextt[x][j];
        }
        if(x) v.push_back({i, x});
    }
    int M = 1e9;
    set<pair<int,int> > s;
    for(int i = v.size()-1; i >= 0; i--){
        if(v[i].second >= M) continue;
        M = v[i].second;
        s.insert({v[i].first, v[i].second});
    }
    string ans = "";
    while(q--){
        int l, r;
        scanf("%d%d", &l,&r);
        auto it = s.lower_bound({l,-1});
        if(it != s.end() && (*it).second <= r) ans += '1';
        else ans += '0';
    }
    cout << ans<<endl;


}