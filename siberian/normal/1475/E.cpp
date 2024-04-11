#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

const int N = 1e3 + 10;
int c[N][N];

void build() {
    for (int i = 0; i < N; ++i) {
        c[i][i] = c[i][0] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    sort(all(a));
    reverse(all(a));
    int need = a[k - 1];
    int cntNeed = k;
    int cntHave = 0;
    for (auto i : a) {
        if (i > need) {
            cntNeed--;
        } else if (i == need) {
            cntHave++;
        }
    }
    // cerr << "cntNeed = " << cntNeed << " cntHave = " << cntHave << endl;
    cout << c[cntHave][cntNeed] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    build();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}