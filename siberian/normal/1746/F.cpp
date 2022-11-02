#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 3e5 + 10, B = 30;
int n, q;
int a[N];
int coord[2 * N];
int top = 0;
int query[N][4];
bool ans[N];

void compress() {
    sort(coord, coord + top);
    top = unique(coord, coord + top) - coord;
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(coord, coord + top, a[i]) - coord;
    }
    for (int i = 0; i < q; ++i) {
        if (query[i][0] == 1) {
            query[i][2] = lower_bound(coord, coord + top, query[i][2]) - coord;
        }
    }
}

int val[2 * N];

void gen() {
    for (int i = 0; i < top; ++i) {
        do {
            val[i] = rnd();
            if (val[i] < 0) {
                val[i] = -val[i];
            }
        } while (val[i] <= 0);
    }
}

ll f[N];

void upd(int pos, ll a) {
    for (; pos < n; pos |= pos + 1) {
        f[pos] += a;
    }
}

ll get(int r) {
    ll ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        ans += f[r];
    }
    return ans;
}

ll get(int l, int r) {
    return get(r) - get(l - 1);
}

int cur_val[N];

void relax() {
    fill(f, f + n, 0);
    gen();
    for (int i = 0; i < n; ++i) {
        upd(i, val[a[i]]);
        cur_val[i] = a[i];
    }
    for (int i = 0; i < q; ++i) {
        if (query[i][0] == 1) {
            upd(query[i][1], (ll)val[query[i][2]] - (ll)val[cur_val[query[i][1]]]);
            cur_val[query[i][1]] = query[i][2];
        } else {
            if (!ans[i]) {
                continue;
            }
            if ((query[i][2] - query[i][1] + 1) % query[i][3] != 0) {
                ans[i] = false;
            } else if (get(query[i][1], query[i][2]) % query[i][3] != 0) {
                ans[i] = false;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        coord[top++] = a[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> query[i][0];
        for (int j = 1; j <= 1 + query[i][0]; ++j) {
            cin >> query[i][j];
        }
        if (query[i][0] == 1) {
            query[i][1]--;
            coord[top++] = query[i][2];
        } else if (query[i][0] == 2) {
            query[i][1]--;
            query[i][2]--;
        } else {
            throw;
        }
    }
    compress();
    fill(ans, ans + q, true);
    while ((double)clock() / CLOCKS_PER_SEC < 2.5) {
        relax();
    }
    for (int i = 0; i < q; ++i) {
        if (query[i][0] == 2) {
            if (ans[i]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}