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
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

vector<int> r[N], c[N];

void solve() {
    int n, m;
    cin >> n >> m;


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;

            c[x].push_back(j);
            r[x].push_back(i);
        }
    }

    li ans = 0;
    for(int i = 0; i < N; i++) {
        sort(c[i].begin(), c[i].end());

        for(int j = 0; j < c[i].size(); j++) {
            ans += (int(c[i].size()) - j * 2 - 1) * 1ll * c[i][j];
            ans += (int(r[i].size()) - j * 2 - 1) * 1ll * r[i][j];
        }
    }

    cout << -ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}