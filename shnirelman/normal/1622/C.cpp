#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 998244353;//1e9 + 7;
const int A = 26;

mt19937 rnd(3432);


/*
4
1 10
20
2 69
6 9
7 8
1 2 1 3 1 2 1
10 1
1 2 3 1 2 6 1 6 8 10

1
10 1
1 2 3 1 2 6 1 6 8 10
*/

void solve() {
    int n;
    li k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    li sum = 0;
    for(int i = 1; i < n; i++)
        sum += a[i];

//    for(int i = 0; i < n; i++) {
//        cout << a[i] << ' ';
//    }
//    cout << endl;

//    if(sum <= k) {
//        cout << 0 << endl;
//    }

    li ans = INF64;
    for(int i = 0; i < n; i++) {
        li l = -1, r = INF64;
        while(r - l > 1) {
            li m = (l + r) / 2;

//            li res = sum + (a[0] - m) * (i + 1);

            if(sum + ld(a[0] - m) * (i + 1) < -INF64 || sum + ld(a[0] - m) * 1ll * (i + 1) <= k)
                r = m;
            else
                l = m;
        }

        ans = min(ans, i + r);

//        cout << i << ' ' << sum << ' ' << x << ' ' << i + max(0ll, x) << endl;
        sum -= a[n - i - 1];
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}