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
const li INF64 = 2e18 + 13;
const int N = 1e6 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;

/*
2 3
1 2
*/

int a[N];
bool b[N];

void solve(bool debug_out) {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = true;
    }

    int ans = 0;
    for(int i = N - 1; i >= 1; i--) {
        if(b[i]) {
            ans++;
        } else {
            int g = 0;
            int cnt = 0;
            for(int j = 2; j * i < N; j++) {
                if(b[i * j]) {
                    g = __gcd(g, j);
                    cnt++;
                }
            }

            if(cnt >= 1) {
                err << i << ' ' << g << ' ' << cnt << endl;
            }

            if(cnt >= 2 && g == 1) {
                b[i] = true;
                ans++;
            }
        }
    }

    cout << ans - n << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve(0);
}