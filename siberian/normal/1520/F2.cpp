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

const int N = 2e5 + 10;
int n, t;
int fenwick[N];

int getFenw(int r) {
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        ans += fenwick[r];
    }
    return ans;
}

void updFenw(int pos, int val = 1) {
    for (; pos < N; pos |= pos + 1) {
        fenwick[pos] += val;
    }
}

int ans[N];

int query(int pos) {
    if (ans[pos] == -1) {
        cout << "? " << 1 << ' ' << pos + 1 << endl;
        cin >> ans[pos];
        ans[pos] -= getFenw(pos);
    }
    return ans[pos] + getFenw(pos);
}

bool check(int m, int k) {
    return m + 1 - query(m) < k;
}

void outAns(int pos) {
    updFenw(pos);
    cout << "! " << pos + 1 << endl;
}



void solve() {
    int k;
    cin >> k;
    int l = -1, r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m, k)) {
            l = m;
        } else {
            r = m;
        }
    }
    outAns(r);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> t;
    fill(ans, ans + N, -1);
    fill(fenwick, fenwick + N, 0);
    while (t--) {
        solve();
    }
    return 0;
}