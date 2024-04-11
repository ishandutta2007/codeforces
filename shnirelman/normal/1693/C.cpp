#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 3e6 + 13;
const int LOGN = 30;
const int A = 26;

/*

*/


vector<int> g[N], r[N];
map<int, int> mp[N], rmp[N];
int res[N];
int cur_del[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        r[u].push_back(v);

        mp[v][u]++;
        rmp[u][v]++;

        cur_del[v]++;
    }

    for(int i = 0; i < n; i++) {
        res[i] = INF;
//        cur_del[i] = mp[i].size();
    }

    res[n - 1] = 0;

    set<pii> st;
    st.emplace(res[n - 1], n - 1);

    while(!st.empty()) {
        int v = st.begin()->s;
        st.erase(st.begin());

//        cout << v << ' ' << res[v] << ' ' << rmp[v].size() << endl;

        for(pii ed : rmp[v]) {
            int u = ed.f, w = ed.s;

//            cout << "go " << v << " -> " << u << " new res = " << res[v] + cur_del[u] - w + 1 << endl;
//            cout << "w = " << w << endl;
            cur_del[u] -= w;
            if(res[u] >= res[v] + cur_del[u] + 1) {
                st.erase(pii(res[u], u));
//                cur_del[u] -= w;
                res[u] = res[v] + cur_del[u] + 1;
                st.emplace(res[u], u);
            }
        }
    }

    cout << res[0] << endl;
}