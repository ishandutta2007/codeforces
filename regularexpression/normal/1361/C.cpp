#include<bits/stdc++.h>
using namespace std;

const int MAX_MEM = 3e8;

char mem[MAX_MEM];
int mempos;

inline void *operator new(size_t n) {
    char *res = mem + mempos;
    mempos += n;
    return (void*)res;
}

inline void operator delete(void*) {}

//#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()

const int N = 1 << 20;

int n;
int a[N], b[N];
set<pair<int, int>> g[N];
vector<int> gg[N], way;
bool was[N];

void zhfs(int v) {
    was[v] = 1;
    for (auto u : gg[v]) {
        if (!was[u]) zhfs(u);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    if (n == 1) {
        int z = a[0] ^ b[0];
        int q = 0;
        while (q + 1 <= 20 && z % (1 << (q + 1)) == 0) ++q;
        cout << q << '\n' << 2 << " " << 1 << '\n';
        return 0;
    }
    int lo = 0, hi = 21;
    while (hi - lo > 1) {
        int mi = (lo + hi) / 2;
        int mask = (1 << mi) - 1;
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cnt[a[i] & mask]++;
            cnt[b[i] & mask]++;
            gg[a[i] & mask].clear();
            gg[b[i] & mask].clear();
        }
        bool ok = 1;
        for (auto e : cnt) {
            if (e.y & 1) {
                ok = 0;
                break;
            }
        }
        memset(was, 0, sizeof(was));
        for (int i = 0; i < n; ++i) {
            gg[a[i] & mask].pb(b[i] & mask);
            gg[b[i] & mask].pb(a[i] & mask);
        }
        zhfs(a[0] & mask);
        for (int i = 0; i < n; ++i) {
            ok &= was[a[i] & mask];
            ok &= was[b[i] & mask];
            if (!ok) break;
        }
        if (ok) lo = mi; else hi = mi;
    }
    cout << lo << '\n';
    int mask = (1 << lo) - 1;
    for (int i = 0; i < n; ++i) {
        a[i] &= mask;
        b[i] &= mask;
        g[a[i]].insert({b[i], i});
        g[b[i]].insert({a[i], i});
    }
    vector<int> way, st = {a[0]};
    while (!st.empty()) {
        int v = st.back();
        if (g[v].empty()) {
            way.pb(v);
            st.pop_back();
        } else {
            auto ed = *g[v].begin();
            int u = ed.x, id = ed.y;
            g[a[id]].erase({b[id], id});
            g[b[id]].erase({a[id], id});
            st.pb(u);
        }
    }
    map<pair<int, int>, set<int>> ma;
    for (int i = 0; i < n; ++i) {
        ma[{a[i], b[i]}].insert(2 * i);
        ma[{b[i], a[i]}].insert(2 * i + 1);
    }
    vector<int> ans;
    for (int i = 0; i + 1 < way.size(); ++i) {
        int id = *ma[{way[i], way[i + 1]}].begin();
        ma[{a[id / 2], b[id / 2]}].erase(2 * (id / 2));
        ma[{b[id / 2], a[id / 2]}].erase(2 * (id / 2) + 1);
        ans.pb(id + 1);
        ans.pb((id ^ 1) + 1);
    }
    for (auto e : ans) cout << e << " ";
    return 0;
}