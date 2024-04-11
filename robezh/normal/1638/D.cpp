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
typedef pair<int, int> P;

const int N = 1005;

int n, m;
int a[N][N];
int vis[N][N];

int good(int i, int j) {
    if(vis[i][j]) return 0;
    if(!(0 <= i && i + 1 < n && 0 <= j && j + 1 < m)) return 0;
    int c = 0;
    rep(di, 0, 2) {
        rep(dj, 0, 2) {
            int dc = a[i + di][j + dj];
            if(dc == 0) continue;
            if(c && c != dc) return 0;
            c = dc;
        }
    }
    return c;
}

struct Pr {
    int i, j, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
    queue<pii> que;
    vector<Pr> res;
    auto paint = [&](int i, int j) {
        int c = good(i, j);
        if(c) {
            vis[i][j] = 1;
            a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = 0;
            que.push({i, j});
            res.push_back({i, j, c});
//            cout << endl;
//            rep(i, 0, n) {
//                rep(j, 0, m) cout << a[i][j] << " ";
//                cout << endl;
//            }
        }
    };
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            paint(i, j);
        }
    }
    while(!que.empty()) {
        auto p = que.front(); que.pop();
        int i = p.first, j = p.second;
        rep(di, -1, 2) {
            rep(dj, -1, 2) {
                paint(i + di, j + dj);
            }
        }
    }
    reverse(all(res));
    rep(i, 0, n) rep(j, 0, m) if(a[i][j] != 0) return cout << -1 << endl, 0;
    cout << sz(res) << '\n';
    for (auto p : res) cout << p.i + 1 << " " << p.j + 1 << " " << p.c << '\n';



}