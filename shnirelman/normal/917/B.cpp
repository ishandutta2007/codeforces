#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 14;
const int M = 998244353;
const int N = 100 + 13;
const int A = 26;

vector<pii> g[N];

int dp[N][N][A];

int calc(int a, int b, int x) {
    if(dp[a][b][x] != -1)
        return dp[a][b][x];
    dp[a][b][x] = 0;

    for(auto p : g[a]) {
        int c = p.f;
        int y = p.s;

        if(y >= x && calc(b, c, y) == 0) {
//            cout << a << ' ' << b << ' '<<
            return dp[a][b][x] = 1;
        }

    }
    return 0;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < A; k++)
                dp[i][j][k] = -1;

    for(int i = 0; i < m; i++) {
        int a, b, x;
        char c;
        cin >> a >> b >> c;

        a--;
        b--;
        x = c - 'a';

        g[a].emplace_back(b, x);
//        g[b].emplace_back(a, x);
    }

    for(int a = 0; a < n; a++) {
        for(int b = 0; b < n; b++) {
            cout << char('B' - calc(a, b, 0));
        }
        cout << endl;
    }
}