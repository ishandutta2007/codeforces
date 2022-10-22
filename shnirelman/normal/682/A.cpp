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
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
//const int M = 1e9 + 7;
const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int mul(int a, int b) {
    return a * 1ll * b % M;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    li ans = 0;
    for(int i = 1; i <= 5; i++) {
        int a = 0;
        int b = 0;
        for(int j = i; j <= 1000013; j += 5) {
            a += (j <= n);
//            b += (j <= m);
        }

        for(int j = (i == 5 ? 5 : 5 - i); j <= 1000013; j += 5) {
//            a += (j <= n);
            b += (j <= m);
        }

//        cout << i << ' ' << a << ' ' << b << endl;

        ans += a * 1ll * b;
    }

    cout << ans << endl;
}