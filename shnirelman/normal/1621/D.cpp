#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 500 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

int a[N][N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n * 2; i++) {
        for(int j = 0; j < n * 2; j++) {
            cin >> a[i][j];
        }
    }

    li ans = 0;
    for(int i = n; i < n * 2; i++) {
        for(int j = n; j < n * 2; j++)
            ans += a[i][j];
    }

    ans += min({a[0][n], a[0][n * 2 - 1], a[n - 1][n], a[n - 1][n * 2 - 1], a[n][0], a[n][n - 1], a[n * 2 - 1][0], a[n * 2 - 1][n - 1]});

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