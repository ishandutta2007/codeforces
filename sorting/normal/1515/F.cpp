#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 3;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int n, m, x;
ll a[N];

int p[N], sz[N];
vector<array<int, 2>> adj[N];
array<int, 3> e[N];
set<pair<ll, int>> s;
bool vis[N];

int get_p(int x){
    if(p[x] == x) return x;
    return p[x] = get_p(p[x]);
}
void init(){
    for(int i = 1; i <= n; ++i)
        p[i] = i, sz[i] = 1 + adj[i].size();
}
bool unite(int x, int y){
    x = get_p(x), y = get_p(y);
    if(x == y) return false;
    if(sz[x] < sz[y]) swap(x, y);

    sz[x] += sz[y];
    for(auto [to, idx]: adj[y])
        adj[x].push_back({to, idx});
    p[y] = x;
    s.erase({a[x], x});
    s.erase({a[y], y});
    a[x] += a[y];
    a[x] -= ::x;
    s.insert({a[x], x});
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
        e[i] = {x, y, i};
    }
    init();

    for(int i = 1; i <= n; ++i)
        s.insert({a[i], i});

    ll sum = 0;
    for(int i = 1; i <= n; ++i)
        sum += a[i];

    if(sum < (ll)(n - 1) * x){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    int cnt = 0;
    while(cnt != n - 1){
        auto [sz_u, u] = *s.rbegin();

        while(true){
            auto [to, idx] = adj[u].back();
            adj[u].pop_back();
            to = get_p(to);
            if(to != u){
                unite(to, u);
                ++cnt;
                cout << idx + 1 << "\n";
                break;
            }
        }
    }
}