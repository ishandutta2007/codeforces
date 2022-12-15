#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<vector<int>> a(2, vector<int>(n + 1));
        vector<vector<int>> adj(n + 1);
        vector<bool> vis(n + 1, false);
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < n; ++j)
                cin >> a[i][j];

        for(int i = 0; i < n; ++i)
            adj[a[0][i]].push_back(a[1][i]);

        std::function<void(int)> f = [&](int u) -> void{
            vis[u] = true;
            for(int to: adj[u])
                if(!vis[to])
                    f(to);
        };

        ll ans = 1;
        for(int i = 1; i <= n; ++i)
            if(!vis[i]){
                ans <<= 1;
                if(ans >= MOD) ans -= MOD;
                f(i);
            }
        cout << ans << "\n";
    }
}