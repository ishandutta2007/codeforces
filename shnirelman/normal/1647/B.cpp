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
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

/*
*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool res = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '1') {
                if(i + 1 < n && a[i + 1][j] == '0') {
                    if(j + 1 < m && a[i][j + 1] == '1' && a[i + 1][j + 1] == '1')
                        res = false;
                    if(j - 1 >= 0 && a[i][j - 1] == '1' && a[i + 1][j - 1] == '1')
                        res = false;
                }

                if(i - 1 >= 0 && a[i - 1][j] == '0') {
                    if(j + 1 < m && a[i][j + 1] == '1' && a[i - 1][j + 1] == '1')
                        res = false;
                    if(j - 1 >= 0 && a[i][j - 1] == '1' && a[i - 1][j - 1] == '1')
                        res = false;
                }

                if(j + 1 < m && a[i][j + 1] == '0') {
                    if(i + 1 < n && a[i + 1][j] == '1' && a[i + 1][j + 1] == '1')
                        res = false;
                    if(i - 1 >= 0 && a[i - 1][j] == '1' && a[i - 1][j + 1] == '1')
                        res = false;
                }

                if(j - 1 >= 0 && a[i][j - 1] == '0') {
                    if(i + 1 < n && a[i + 1][j] == '1' && a[i + 1][j - 1] == '1')
                        res = false;
                    if(i - 1 >= 0 && a[i - 1][j] == '1' && a[i - 1][j - 1] == '1')
                        res = false;
                }
            }
        }
    }


    cout << (res ? "YES\n" : "NO\n");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}