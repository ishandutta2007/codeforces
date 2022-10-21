#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 505, K = 15;

int n, m, k;
int hor[N][N], ver[N][N];
int dis[N][N][K];

void umin(int &to, int val) {
    to = min(to, val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    rep(i, 0, n) {
        rep(j, 0, m - 1) cin >> hor[i][j];
    }
    rep(i, 0, n - 1) {
        rep(j, 0, m) cin >> ver[i][j];
    }
    for(int ki = 1; ki <= 10; ki++) {
        rep(i, 0, n) {
            rep(j, 0, m) {
                dis[i][j][ki] = (int)1e9;
                if(i > 0) umin(dis[i][j][ki], dis[i - 1][j][ki - 1] + ver[i - 1][j]);
                if(i + 1 < n) umin(dis[i][j][ki], dis[i + 1][j][ki - 1] + ver[i][j]);
                if(j > 0) umin(dis[i][j][ki], dis[i][j - 1][ki - 1] + hor[i][j - 1]);
                if(j + 1 < m) umin(dis[i][j][ki], dis[i][j + 1][ki - 1] + hor[i][j]);
            }
        }
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(k % 2 == 1) cout << -1 << " ";
            else cout << 2 * dis[i][j][k / 2] << " ";
        }
        cout << '\n';
    }

}