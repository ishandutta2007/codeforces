#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;

int n, h[N], mx[N];
vector<int> adj[N];

ll dfs(int u, int p = -1){
    ll ans = 0;
    mx[u] = 0;
    int mx2 = 0;
    for(int to: adj[u]){
        if(to == p) continue;

        ans += dfs(to, u);
        if(mx[to] >= mx[u]){
            if(mx[u] > mx2)
                mx2 = mx[u];
            mx[u] = mx[to];
        }
        else if(mx[to] > mx2)
            mx2 = mx[to];
    }

    ans += max(0, h[u] - mx[u]);
    if(p == -1) ans += max(0, h[u] - mx2);
    check_max(mx[u], h[u]);

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int mx_idx = 0;
    for(int i = 1; i <= n; ++i){
        cin >> h[i];
        if(h[i] > h[mx_idx]){
            mx_idx = i;
        }
    }

    for(int i = 1; i <= n - 1; ++i){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << dfs(mx_idx) << "\n";
}