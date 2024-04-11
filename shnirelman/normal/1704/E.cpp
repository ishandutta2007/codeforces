#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<__int128, __int128>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int M = 1e9 + 7;
//const int M = 32768;
const int N = 1000 + 13;
const int LOGN = 20;


mt19937 rnd(54787);

/*
*/

vector<int> g[N], r[N];
int a[N];
bool used[N];
vector<int> ts;
vector<pli> seg[N];

void dfs(int v) {
    used[v] = true;
    for(int u : g[v])
        if(!used[u])
            dfs(u);
    ts.push_back(v);
}

void solve() {
    int n, m;
    cin >> n >> m;

    ts.erase(ts.begin(), ts.end());
    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        r[i].erase(r[i].begin(), r[i].end());
        seg[i].erase(seg[i].begin(), seg[i].end());
        used[i] = false;
    }

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        r[u].push_back(v);
    }

    for(int i = 0; i < n; i++)
        if(!used[i])
            dfs(i);

    reverse(ts.begin(), ts.end());
//return;
    for(int v : ts) {
//        cout << v << endl;
        vector<pli> s;
        if(a[v] > 0)
            s.emplace_back(0ll, a[v] * 1ll);

        for(int u : r[v])
            for(auto p : seg[u])
                s.emplace_back(p.f + 1, p.s + 1);

        sort(s.begin(), s.end());
        __int128 cur = -1;
        for(int i = 0; i < int(s.size()); i++) {
            if(s[i].f <= cur)
                seg[v].back().s += s[i].s - s[i].f;
            else
                seg[v].push_back(s[i]);
            cur = seg[v].back().s;
        }

//        cout << "v : ";
//        for(auto p : seg[v])
//            cout << "(" << p.f << ", " << p.s << ") ";
//        cout << endl;
    }

    __int128 mx = 0;
    for(int i = 0; i < n; i++)
        if(!seg[i].empty())
            mx = max(mx, seg[i].back().s);

//    int v = ts.back();
    cout << int(mx % M) << endl;
//    cout << (seg[v].empty() ? 0 : seg[v].back().s % M) << endl;
//    cout << (seg[v].empty() ? 0ll : seg[v].back().s) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}