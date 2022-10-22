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
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
//const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());

    int x = b[0], y = b[n - 1];
    for(int i = 0; i < n; i++) {
        int x1 = b[i];
        int cnt = (n + k + 1) / 2;
        if(i + cnt > n)
            break;
        int y1 = b[i + cnt - 1];

        if(y1 - x1 < y - x) {
            x = x1;
            y = y1;
        }
    }

    cout << x << ' ' << y << '\n';

    int cur = 0;
    int lst = 0;
    for(int i = 0; i < n && k > 1; i++) {
        cur += (x <= a[i] && a[i] <= y ? 1 : -1);
        if(cur == 1) {
            cout << lst + 1 << ' ' << i + 1 << '\n';
            lst = i + 1;
            cur = 0;
            k--;
        }
    }
    cout << lst + 1 << ' ' << n << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}