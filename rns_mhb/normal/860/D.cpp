#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int> > adj(n+1), tail(n+1);
    vector <int> d(n+1, 0);
    while(m --) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector <tuple<int, int, int> > ans;
    function <void(int,int)> dfs = [&](int x, int p) {
        d[x] = d[p] + 1;
        for(auto y : adj[x]) {
            if(y == p) continue;
            if(d[y]) {
                if(d[y] < d[x]) tail[y].push_back(x);
            }
            else {
                dfs(y, x);
                if(tail[y].size() == 0) tail[x].push_back(y);
                else {
                    ans.push_back(make_tuple(x, y, tail[y][0]));
                    tail[y].clear();
                }
            }
        }
        while(tail[x].size() > 1) {
            int y = tail[x].back(); tail[x].pop_back();
            int z = tail[x].back(); tail[x].pop_back();
            ans.push_back(make_tuple(y, x, z));
        }
    };
    for(int i = 1; i <= n; i ++) if(!d[i]) dfs(i, 0);
    cout << ans.size() << endl;
    for(auto x : ans) cout << get<0>(x) << ' ' << get<1>(x) << ' ' << get<2>(x) << endl;
}