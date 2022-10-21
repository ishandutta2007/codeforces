#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = 405, INF = (int)1e9;

int n, m;
string str[N];
int ps[N][N];

int getrect(int i1, int j1, int i2, int j2, int v) {
    int cur = ps[i2][j2] - ps[i1 - 1][j2] - ps[i2][j1 - 1] + ps[i1 - 1][j1 - 1];
    if(v == 0) return cur;
    else return (i2 - i1 + 1) * (j2 - j1 + 1) - cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 1, n + 1) cin >> str[i], str[i] = " " + str[i];
        int res = n * m;
        rep(i, 1, n + 1) {
            rep(j, 1, m + 1) {
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + (str[i][j] - '0');
            }
        }
        for (int il = 2; il <= n; il++) {
            for (int ir = il + 2; ir + 1 <= n; ir++) {
                int mn = INF;
                for (int j = 4; j <= m; j++) {
                    int cur = getrect(il, j - 3, ir, j - 3, 1) - getrect(il, 1, ir, j - 3, 0)
                              - getrect(il - 1, 1, il - 1, j - 3, 1) - getrect(ir + 1, 1, ir + 1, j - 3, 1);
                    mn = min(cur, mn);
                    res = min(res, mn + getrect(il, 1, ir, j - 1, 0) + getrect(il, j, ir, j, 1)
                      + getrect(il - 1, 1, il - 1, j - 1, 1) + getrect(ir + 1, 1, ir + 1, j - 1, 1));
                }

            }
        }
        cout << res << '\n';
    }

}