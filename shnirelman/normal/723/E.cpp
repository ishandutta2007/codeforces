//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 50000 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 22;
const int A = 52;


/*
*/
pii e[N];
vector<int> g[N];
int cur[N];
bool used[N];
//vector<int> st;
int m;

void dfs(int v) {
    for( ; cur[v] < g[v].size(); cur[v]++) {
        int ed = g[v][cur[v]];
        if(!used[ed]) {
            used[ed] = true;
            int u = e[ed].f ^ e[ed].s ^ v;

            dfs(u);

            if(ed < m) {
                if(e[ed].f != v)
                    swap(e[ed].f, e[ed].s);
//                st.push_back(ed);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n >> m;

    for(int i = 0; i < n + m; i++) {
        used[i] = false;
    }

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
        cur[i] = 0;

    }

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        e[i] = {v, u};

        g[v].push_back(i);
        g[u].push_back(i);
    }

    vector<int> odd;
    for(int i = 0; i < n; i++) {
        if(g[i].size() % 2 != 0) {
            odd.push_back(i);
        }
    }

    for(int i = 0; i < odd.size(); i += 2) {
        e[m + i / 2] = {odd[i], odd[i + 1]};
        g[odd[i]].push_back(m + i / 2);
        g[odd[i + 1]].push_back(m + i / 2);
    }

    for(int i = 0; i < n; i++) {
        if(cur[i] < g[i].size()) {
            dfs(i);
        }
    }

    cout << n - odd.size() << endl;
    for(int i = 0; i < m; i++) {
        cout << e[i].f + 1 << ' ' << e[i].s + 1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;

    while(t--)
        solve();
}