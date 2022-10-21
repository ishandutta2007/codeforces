#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 505;

int n, m;
string str[N];
vi G[N * N];
vi pos[N * N];
int res[N][N];
int col[N * N];
int dx[4] = {0, -1, 0 , 1}, dy[4] = {1,  0, -1, 0};

bool in_bound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int v, int cc) {
    col[v] = cc;
    res[v / m][v % m] = cc ? 1 : 4;
    for (int nxt : G[v]) {
        if(col[nxt] != -1) {
            assert(col[nxt] == !cc);
        } else {
            dfs(nxt, !cc);
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) cin >> str[i];
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(str[i][j] == 'X') {
                rep(d, 0, 4) {
                    int nx = i + dx[d], ny = j + dy[d];
                    if(in_bound(nx, ny) && str[nx][ny] == '.') pos[i * m + j].push_back(nx * m + ny);
                }
                if(sz(pos[i * m + j]) % 2 != 0) {
                    return cout << "NO\n", 0;
                }
                res[i][j] = sz(pos[i * m + j]) / 2 * 5;
                for (int k = 0; k < sz(pos[i * m + j]); k += 2) {
                    int u = pos[i * m + j][k];
                    int v = pos[i * m + j][k + 1];
                    G[u].push_back(v);
                    G[v].push_back(u);
                }
            }
        }
    }
    memset(col, -1, sizeof(col));
    rep(i, 0, n * m) {
        if(str[i / m][i % m] == '.' && col[i] == -1) {
            dfs(i, 0);
        }
    }

    cout << "YES\n";
    rep(i, 0, n) {
        rep(j, 0, m) cout << res[i][j] << " ";
        cout << endl;
    }

}