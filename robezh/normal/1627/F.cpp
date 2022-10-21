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
typedef pair<int, pii> P;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)505, INF = (int)1e9 + 50;

int k, n;
int hor[N][N], ver[N][N];
int dis[N][N];
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

bool in_bound(int x, int y) {
    return x >= 0 && x <= k && y >= 0 && y <= k;
}

int get_raw_cost(int i0, int j0, int i1, int j1) {
    if(i0 == i1) return ver[i0][max(j0, j1)];
    else return hor[max(i0, i1)][j0];
}

int get_cost(int i0, int j0, int i1, int j1) {
    return get_raw_cost(i0, j0, i1, j1) +
        get_raw_cost(k - i0, k - j0, k - i1, k - j1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        rep(i, 0, k + 1) {
            fill(hor[i], hor[i] + k + 1, 0);
            fill(ver[i], ver[i] + k + 1, 0);
        }
        rep(i, 0, n) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            if(r1 == r2) {
                if(c1 > c2) swap(c1, c2);
                hor[r1][c1]++;
            } else {
                if(r1 > r2) swap(r1, r2);
                ver[r1][c1]++;
            }
        }
        rep(i, 0, k + 1) fill(dis[i], dis[i] + k + 1, INF);
        priority_queue<P, vector<P>, greater<P>> pque;
        dis[k / 2][k / 2] = 0;
        pque.push({0, {k / 2, k / 2}});
        int res = INF;
        while(!pque.empty()) {
            auto p = pque.top(); pque.pop();
            int ds = p.first, x = p.second.first, y = p.second.second;
            if(dis[x][y] != ds) continue;
            if(x == 0 || x == k || y == 0 || y == k) res = min(res, ds);
            rep(d, 0, 4) {
                int nx = x + dx[d], ny = y + dy[d];
                if(in_bound(nx, ny)) {
                    int nxt_ds = ds + get_cost(x, y, nx, ny);
                    if(nxt_ds < dis[nx][ny]) {
                        dis[nx][ny] = nxt_ds;
                        pque.push({dis[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        cout << n - res << '\n';
    }


}