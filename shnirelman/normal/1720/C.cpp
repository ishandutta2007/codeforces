#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 998244353;
const int g = 3;
const int ALF = (1 << 20) - 3;
const int N = 2e5 + 13;
//const int N = 20 + 13;
const int K = 2e5 + 13;
//const int K = 20 + 13;
const int LOGN = 23;
const ld PI = acos(-1);
const ld eps = 1e-4;
const int S = 1007;
//const int B = 100;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '1') {
                ans++;
            } else {
//                int cnt = 0;

//                bool dw = (i + 1 < n && a[i + 1][j] == '0');
//                bool rg = (j + 1 < m && a[i][j + 1] == '0');
//                bool up = (i - 1 >= 0 && a[i - 1][j] == '0');
//                bool lf = (j - 1 >= 0 && a[i][j - 1] == '0');
//
//                if((dw || up) && (lf || rg))
//                    mx = 3;
//                else if(dw || up || lf || rg)
//                    mx = max(mx, 2);
//                else
//                    mx = max(mx, 1);
            }
        }
    }

    if(ans == 0) {
        cout << 0 << endl;
        return;
    }

    int mn = 3;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            for(int i1 = i; i1 < i + 2; i1++) {
                for(int j1 = j; j1 < j + 2; j1++) {
                    int cnt = (a[i][j] - '0') + (a[i + 1][j] - '0') + (a[i][j + 1] - '0') + (a[i + 1][j + 1] - '0') - (a[i1][j1] - '0');
                    if(cnt > 0)
                        mn = min(mn, cnt);
                }
            }

        }
    }

    cout << ans - mn + 1 << endl;

//    if(ans == n * m)
//        cout << n * m - 2 << endl;
//    else
//        cout

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}