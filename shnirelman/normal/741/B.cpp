//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1000 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 20;

/*
3 1
1 0 0
*/

int p[N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

void unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x != y) {
        p[y] = x;
    }
}

int a[N], b[N];
vector<pii> ch[N];
int dp[N][N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, w;
    cin >> n >> m >> w;

    for(int i = 0; i < n; i++) {
        p[i] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        unite(v, u);
    }

    for(int i = 0; i < n; i++) {
        ch[getp(i)].emplace_back(a[i], b[i]);
    }

    for(int i = 0; i < n; i++) {
        int sa = 0, sb = 0;
        for(auto pr : ch[i]) {
            sa += pr.f;
            sb += pr.s;
        }

        ch[i].emplace_back(sa, sb);
        ch[i].emplace_back(0, 0);
    }

    for(int i = 0; i < n; i++) {
        for(auto pr : ch[i]) {
//            cout << i << ' ' << pr.f << ' ' << pr.s << endl;
            for(int j = 0; j + pr.f <= w; j++) {
                dp[i + 1][j + pr.f] = max(dp[i + 1][j + pr.f], dp[i][j] + pr.s);
            }
        }

//        for(int j = 0; j <= w; j++) {
//            cout << "dp " << i + 1 << ' ' << j << ' ' << dp[i + 1][j] << endl;
//        }
    }

    int mx = 0;
    for(int i = 0; i <= w; i++)
        mx = max(mx, dp[n][i]);

    cout << mx << endl;
}