#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const li INF64 = 4e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

//    int m = max(0, k - n);
//    for(int i = 0; i < n; i++)
//        a[i] += m;
//    k -= m;

    if(k <= n) {
        li res = 0;
        li cur = 0;
        for(int i = 0; i < k; i++) {
            cur += a[i] + i;
        }

        for(int i = 0; i + k <= n; i++) {
            res = max(res, cur);
            if(i + k < n)
                cur += a[i + k] - a[i];
        }
        cout << res << endl;
    } else if(n > 1) {
        li res = k * 1ll * n;
        for(int i = 0; i < n; i++) {
            res += a[i];
        }

        res -= n * 1ll * (n + 1) / 2;

        cout << res << endl;
//
//        int cnt = k / (n - 1);
//
//        res +=
    } else {
        cout << a[0] + k - 1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}