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

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1000 + 13;
const int LOGN = 20;
const int K = 12;
//const int M = 1e9 + 7;
const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h, k;
    cin >> n >> h >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    li ans = 0;
    int cur = 0;
    for(int i = 0; i < n; ) {
        bool fl = false;
        while(i < n && cur + a[i] <= h) {
            fl = true;
            cur += a[i++];
        }

        if(fl) {
            ans += (cur / k);
            cur %= k;
        } else {
            ans++;
            cur = 0;
        }

//        cout << ans << ' ' << cur << ' ' << i << endl;
    }

    ans += (cur > 0);

    cout << ans << endl;
}