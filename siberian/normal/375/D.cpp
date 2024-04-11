#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a)        \
    for (auto& i : a) \
    cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template <typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
    if (y < x)
        x = y;
}

template <typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y)
        x = y;
}


const int N = 1e5 + 10;
const int B = 300;

struct Query{
    int l, r, id, k;
    bool operator<(const Query& other) const {
        if (l / B != other.l / B) {
            return l < other.l;
        } else {
            return r < other.r;
        }
    }
};

int n, q;
vector<int> g[N];
int c[N];
Query queries[N];
int tin[N], tout[N], timer = 0;
int order[N];
int ans[N];

void dfs(int v, int p) {
    tin[v] = timer++;
    order[tin[v]] = v;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    tout[v] = timer - 1;
}

int cnt[N];
int fans[N];
int prefFans[N];

void updFans(int pos, int val) {
    if (pos > 0) {
        // cerr << "updFans: " << pos << " " << val << endl;
        fans[pos] += val;
        prefFans[pos / B] += val;
    }
}

int getSum(int l, int r) {
    if (l > r) {
        return 0;
    }
    int L = l / B;
    int R = r / B;
    if (L == R) {
        int ans = 0;
        for (int i = l; i <= r; ++i) {
            ans += fans[i];
        }
        return ans;
    } else {
        int ans = 0;
        while (l / B == L) {
            ans += fans[l];
            ++l;
        }
        ++L;
        while (r / B == R) {
            ans += fans[r];
            --r;
        }
        --R;
        while (L <= R) {
            ans += prefFans[L];
            ++L;
        }
        return ans;
    }
}

void upd(int pos, int val) {
    int color = c[order[pos]];
    updFans(cnt[color], -1);
    cnt[color] += val;
    updFans(cnt[color], +1);
}

int getAns(int k) {
    return getSum(k, N - 1);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    for (int i = 0; i < q; ++i) {
        int v, k;
        cin >> v >> k;
        --v;
        queries[i] = {tin[v], tout[v], i, k};
    }
    sort(queries, queries + q);
    int L = 0, R = -1;
    for (int i = 0; i < q; ++i) {
        int l = queries[i].l;
        int r = queries[i].r;
        int id = queries[i].id;
        int k = queries[i].k;
        while (l < L) {
            --L;
            upd(L, +1);
        }
        while (R < r) {
            ++R;
            upd(R, +1);
        }
        while (L < l) {
            upd(L, -1);
            ++L;
        }
        while (r < R) {
            upd(R, -1);
            --R;
        }
        ans[id] = getAns(k);
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}