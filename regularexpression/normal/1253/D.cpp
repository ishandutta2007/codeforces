#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

typedef long long ll;
typedef long double ld;

#define int long long

const int N = 2e5 + 12;
const int INF = 2e18 + 12;

int n, m;
bool us[N];

int p[N], sz[N], mn[N], mx[N];

int get(int v) {
    return p[v] == v ? v : p[v] = get(p[v]);
}

bool un(int v, int u) {
    v = get(v);
    u = get(u);
    if (v != u) {
        if (sz[v] > sz[u]) swap(v, u);
        p[v] = u;
        sz[u] += sz[v];
        mx[u] = max(mx[u], mx[v]);
        mn[u] = min(mn[u], mn[v]);
        return 1;
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
        mn[i] = i;
        mx[i] = i;
    }
    while (m--) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        un(v, u);
    }
    vector<pair<int, int>> segs;
    for (int i = 0; i < n; i++) {
        if (p[i] == i) {
            segs.pb({mn[i], 1});
            segs.pb({mx[i], -1});
        }
    }
    sort(all(segs));
    vector<pair<int, int>> s;
    int lst = -1;
    int cnt = 0;
    for (auto seg : segs) {
        if (cnt == 0) {
            lst = seg.x;
        }
        cnt += seg.y;
        if (cnt == 0) {
            s.pb({lst, seg.x});
        }
    }
    int ans = 0;
    for (auto el : s) {
        //cout << el.x << " " << el.y << '\n';
        for (int i = el.x; i < el.y; i++) {
            if (un(i, i + 1)) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}