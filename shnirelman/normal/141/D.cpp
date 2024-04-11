#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

vector<pii> g[N];
vector<int> ed[N];
int d[N];
int p[N], pe[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, L;
    cin >> n >> L;

    vector<pair<pii, int>> seg;
    map<pair<pii, int>, int> ind;
    for(int i = 0; i < n; i++) {
        int x, d, t, p;
        cin >> x >> d >> t >> p;

        int l = x - p;
        int r = x + d;
        int w = t + p;

        if(l >= 0) {
            seg.emplace_back(pii(l, r), w);
            ind[seg.back()] = i;
        }
    }

    seg.emplace_back(pii(0, 0), 0);
    seg.emplace_back(pii(L, L), 0);

    sort(seg.begin(), seg.end());
    n = seg.size();

    for(int i = 0; i < n - 1; i++) {
        g[i].emplace_back(i + 1, seg[i + 1].f.f - seg[i].f.f);
        g[i + 1].emplace_back(i, seg[i + 1].f.f - seg[i].f.f);

        ed[i].push_back(-1);
        ed[i + 1].push_back(-1);
    }

//    for(int i = 0; i < n; i++) {
//        g[i].emplace_back(n + i, 0);
//        g[i].emplace_back(i, 0);
//    }

    for(int i = 1; i < n - 1; i++) {
        int j = lower_bound(seg.begin(), seg.end(), pair<pii, int>(pii(seg[i].f.s, 0), 0)) - seg.begin();
        g[i].emplace_back(j, seg[i].s + seg[j].f.f - seg[i].f.s);
//        g[j].emplace_back(i, seg[i].s + seg[j].f.f - seg[i].f.s);

        ed[i].push_back(ind[seg[i]]);

        if(j > 0) {
            j--;

            g[i].emplace_back(j, seg[i].s - seg[j].f.f + seg[i].f.s);
            ed[i].push_back(ind[seg[i]]);
//            g[j].emplace_back(i, seg[i].s - seg[j].f.f + seg[i].f.s);
        }
    }

    for(int i = 0; i < n; i++) {
        d[i] = INF;
    }

    d[0] = 0;
    set<pii> st;
    st.emplace(0, 0);

    while(!st.empty()) {
        int v = st.begin()->s;
        st.erase(st.begin());

        for(int i = 0; i < g[v].size(); i++) {
            int u = g[v][i].f, nd = d[v] + g[v][i].s;

            if(d[u] > nd) {
                st.erase({d[u], u});
                d[u] = nd;
                p[u] = v;
                pe[u] = ed[v][i];
                st.insert({d[u], u});
            }
        }
    }

    cout << d[n - 1] << endl;

    vector<int> ans;
    int v = n - 1;
    while(v != 0) {
        if(pe[v] != -1)
            ans.push_back(pe[v] + 1);
        v = p[v];
    }

    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(int x : ans)
        cout << x << '\n';
}