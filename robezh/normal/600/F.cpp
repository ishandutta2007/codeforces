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
const int N = 2005, M = (int)1e5 + 50;

int D = 0;
int n;
int L, R, m;
//int in[N][N];
int to[N][N];
int col[N][N];

vi G[N];
map<pii, int> mp;
int res[M];

void setcol(int x, int y, int c) {
    col[x][y] = col[y][x] = c;
    to[x][c] = y;
    to[y][c] = x;
}

void find(int x, int y, int c0, int c1) {
    int n0 = c0, n1 = c1;
    vi vs = {x, y};
    int cur = y;
    while(to[cur][c0]) {
        cur = to[cur][c0];
        vs.push_back(cur);
        swap(c0, c1);
    }
    c0 = n0, c1 = n1;
    for(int i = 0; i + 1 < sz(vs); i++) {
        setcol(vs[i], vs[i + 1], c0);
        if(i + 1 == sz(vs) - 1) to[vs[i + 1]][c1] = 0;
        swap(c0, c1);
    }

}

void color(int x, int y) {
    int c0 = -1, c1 = -1;
    rep(c, 1, D + 1) {
        if (!to[x][c] && !to[y][c]) {
            setcol(x, y, c);
            return;
        } else if(!to[x][c]) {
            c0 = c;
        } else if(!to[y][c]) {
            c1 = c;
        }
    }
    assert(c0 != -1 && c1 != -1);
    find(x, y, c0, c1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> R >> m;
    n = L + R;
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        G[a].push_back(b + L);
        G[b + L].push_back(a);
        mp[{a, b + L}] = i;
    }
    rep(i, 1, n + 1) D = max(D, sz(G[i]));
    rep(i, 1, n + 1) {
        for (int nxt : G[i]) {
            if(!col[i][nxt]) color(i, nxt);
        }
    }
    for (auto p : mp) {
        res[p.second] = col[p.first.first][p.first.second];
    }
    cout << D << endl;
    rep(i, 0, m) cout << res[i] << " ";
    cout << endl;

}