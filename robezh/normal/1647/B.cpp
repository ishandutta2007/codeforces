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

const int M = 105 * 105, N = 105;

int f[M];
int lx[M], rx[M], ly[M], ry[M];
int siz[M];
int n, m;

int find(int u) {return f[u] == u ? u : f[u] = find(f[u]);}
void unite(int u, int v) {
    if(f[u] == -1 || f[v] == -1) return ;
    u = find(u), v = find(v);
    if(u == v) return ;
    siz[u] += siz[v];
    lx[u] = min(lx[u], lx[v]);
    ly[u] = min(ly[u], ly[v]);
    rx[u] = max(rx[u], rx[v]);
    ry[u] = max(ry[u], ry[v]);
    f[v] = u;
}

string str[N];

int gid(int i, int j) {
    return i * m + j;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) cin >> str[i];
        rep(i, 0, n) {
            rep(j, 0, m) {
                int id = i * m + j;
                if(str[i][j] - '0') {
                    f[id] = id;
                    lx[id] = rx[id] = i;
                    ly[id] = ry[id] = j;
                    siz[id] = 1;
                } else {
                    f[id] = -1;
                }
            }
        }
        rep(i, 0, n) {
            rep(j, 0, m - 1) {
                unite(gid(i, j), gid(i, j + 1));
            }
        }
        rep(i, 0, n - 1) {
            rep(j, 0, m) unite(gid(i, j), gid(i + 1, j));
        }
        bool good = true;
        rep(i, 0, n * m) {
            if(f[i] == i) {
                good &= ((ry[i] - ly[i] + 1) * (rx[i] - lx[i] + 1) == siz[i]);
//                cout << (ry[i] - ly[i] + 1) * (rx[i] - lx[i] + 1) << " " << siz[i] << endl;
            }
        }
        cout << (good ? "YES" : "NO") << '\n';
    }


}