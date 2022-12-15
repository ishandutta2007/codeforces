#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }

const int N = 400000 + 3;

int n, m, a[N];
string s[N];
vector<vector<pair<int, int>>> adj[N], rev_adj[N];
vector<bool> vis[N];
vector<pair<int, int>> order;
int timer = 0;
vector<int> comp[N];
int cnt[N];

void rev_dfs(int x, int y){
    vis[x][y] = true;
    comp[x][y] = timer;
    for(auto [to_x, to_y]: rev_adj[x][y]){
        if(vis[to_x][to_y]) continue;
        rev_dfs(to_x, to_y);
    }
}

void dfs(int x, int y){
    vis[x][y] = true;
    for(auto [to_x, to_y]: adj[x][y]){
        if(vis[to_x][to_y]) continue;
        dfs(to_x, to_y);
    }
    order.push_back({x, y});
}

bool valid(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m && s[x][y] == '#';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> s[i];

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n; ++i){
        vis[i].resize(m);
        adj[i].resize(m);
        rev_adj[i].resize(m);
        comp[i].resize(m);
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            if(s[i][j] == '.') continue;
            if(valid(i - 1, j)){
                adj[i][j].push_back({i - 1, j});
                rev_adj[i - 1][j].push_back({i, j});
            }
        }

    for(int j = 0; j < m; ++j){
        int prev = -1;
        for(int i = n - 1; i >= 0; --i){
            if(s[i][j] == '#'){
                if(prev != -1){
                    adj[i][j].push_back({prev, j});
                    rev_adj[prev][j].push_back({i, j});
                }
                prev = i;
            }
        }
        if(j != 0){
            prev = -1;
            for(int i = n - 1; i >= 0; --i){
                if(s[i][j - 1] == '#')
                    prev = i;
                if(s[i][j] == '#' && prev != -1){
                    adj[i][j].push_back({prev, j - 1});
                    rev_adj[prev][j - 1].push_back({i, j});
                }
            }
        }
        if(j != m - 1){
            prev = -1;
            for(int i = n - 1; i >= 0; --i){
                if(s[i][j + 1] == '#')
                    prev = i;
                if(s[i][j] == '#' && prev != -1){
                    adj[i][j].push_back({prev, j + 1});
                    rev_adj[prev][j + 1].push_back({i, j});
                }
            }
        }
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(s[i][j] == '#' && !vis[i][j])
                dfs(i, j);

    reverse(order.begin(), order.end());
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            vis[i][j] = false;

    for(auto [x, y]: order)
        if(!vis[x][y]){
            ++timer;
            rev_dfs(x, y);
        }

    for(auto [x, y]: order)
        for(auto [to_x, to_y]: adj[x][y]){
            if(comp[x][y] == comp[to_x][to_y]) continue;
            ++cnt[comp[to_x][to_y]];
        }

    int ans = 0;
    for(int i = 1; i <= timer; ++i)
        ans += !cnt[i];

    cout << ans << "\n";
}