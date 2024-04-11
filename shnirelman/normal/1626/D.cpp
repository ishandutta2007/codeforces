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

//const bool debug_out = false;
const bool debug_out = true;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;
const ld eps = 1e-15;

/*
1
6
2 2 2 1 1 1
*/

int a[N];
int cnt[N];
int s[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i <= n; i++) {
        cnt[i] = s[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + cnt[i];
    }

    int ans = INF;

    for(int k = 1; k < n * 2; k *= 2) {
        int i = upper_bound(s, s + n + 1, k) - s;
        if(i == 1)
            continue;
        for(int m = 1; m < n * 2; m *= 2) {
            int j = upper_bound(s, s + n + 1, m + s[i - 1]) - s;
            if(j == i && j != n + 1)
                continue;

            int p = 1;
            while(p < n - s[j - 1])
                p *= 2;

//            err << k << ' ' << m << ' ' << p << endl;
            int res = k + m + p - n;

            ans = min(ans, res);
        }
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