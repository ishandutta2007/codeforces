#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 1e5 + 10;
int n;
int a[N];
int topAns = 0;
int ans[N];
int nxt[N];

struct Dsu{
    vector<int> par;
    Dsu() {}
    Dsu(int n) {
        par.assign(n, 0);
        iota(all(par), 0);
    }
    int getPar(int v) {
        if (v == par[v]) return v;
        return par[v] = getPar(par[v]);
    }
    void uni(int a, int b) {
        a = getPar(a);
        b = getPar(b);
        if (a == b) return;
        par[b] = a;
    }
};

void process() {
    Dsu dsu(n);
    int pos = 0;
    // cerr << "puhh" << endl;
    // cerr << "nxt = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << nxt[i] << " ";
    // }
    // cerr << endl;
    for (int it = 0, lastDel = 0; it - lastDel <= n + 10; ++it) {
        pos = dsu.getPar(pos);
        if (__gcd(a[pos], a[nxt[pos]]) != 1) {
            dsu.uni(nxt[pos], pos);
            continue;
        }
        if (nxt[pos] == pos) {
            if (a[pos] == 1) {
                ans[topAns++] = pos + 1;
                break;
            } else {
                break;
            }
        }
        lastDel = it;
        ans[topAns++] = nxt[pos] + 1;
        nxt[pos] = nxt[nxt[pos]];

        pos = nxt[pos];
    }
    // cerr << "puhh" << endl;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        nxt[i] = (i + 1) % n;
    }
    topAns = 0;
    process();
    cout << topAns;
    for (int i = 0; i < topAns; ++i) {
        cout << " " << ans[i];
    }
    cout << "\n";
    cout.flush();
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}