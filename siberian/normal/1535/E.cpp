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

const int LOG = 20, N = 3e5 + 10;
int q;
int h[N];
int jump[N][LOG];
int a[N], c[N];

int getJump(int v, int h) {
    for (int i = 0; i < LOG; ++i) {
        if ((h >> i) & 1) {
            v = jump[v][i];
        }
    }
    return v;
}

int getLastNonzero(int v) {
    for (int i = LOG - 1; i >= 0; --i) {
        if (a[jump[v][i]] > 0) {
            v = jump[v][i];
        }
    }
    return v;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> q;
    cin >> a[0] >> c[0];
    h[0] = 0;
    for (int v = 1; v <= q; ++v) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> jump[v][0] >> a[v] >> c[v];
            for (int i = 1; i < LOG; ++i) {
                jump[v][i] = jump[jump[v][i - 1]][i - 1];
            }
            h[v] = h[jump[v][0]] + 1;
        } else {
            int v, w;
            cin >> v >> w;
            int now = getLastNonzero(v);
            ll sumGold = 0;
            ll wGold = 0;
            while (w > 0 && now != v) {
                int add = min(a[now], w);
                a[now] -= add;
                w -= add;
                wGold += add;
                sumGold += (ll)add * c[now];       
                now = getJump(v, h[v] - h[now] - 1);
            } 
            if (w > 0) {
                int add = min(a[now], w);
                a[now] -= add;
                w -= add;
                wGold += add;
                sumGold += (ll)add * c[now];
            }
            cout << wGold << ' ' << sumGold << endl;
        }
    }

    return 0;
}