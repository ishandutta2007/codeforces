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

const int INF = (int)1e9;
const int N = 1505, K = 12;
int a[N][N];

struct Ele {
    short x, y;
    Ele(int x = 0, int y = 0): x(x), y(y){}
    int val() {
        return a[x][y];
    }
};

int getdis(Ele e0, Ele e1) {
    return max(abs(e0.x - e1.x), abs(e0.y - e1.y));
}

struct Que {
    Ele qs[K];
    int sz = 0;
    void add(Ele e) {
        qs[sz++] = e;
    }
};

int n, q;
int have[N * N];
Que U[N][N], L[N][N], UL[N][N];
int res[N][N];
int fres[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            {
                auto &curque = U[i][j];
                curque.add({i, j});
                auto &uque = U[i - 1][j];
                for (int l = 0; l < uque.sz; l++) {
                    if(curque.sz <= q && uque.qs[l].val() != a[i][j]) curque.add(uque.qs[l]);
                }
            }
            {
                auto &curque = L[i][j];
                curque.add({i, j});
                auto &lque = L[i][j - 1];
                for (int l = 0; l < lque.sz; l++) {
                    if(curque.sz <= q && lque.qs[l].val() != a[i][j]) curque.add(lque.qs[l]);
                }
            }
            {
                auto &curque = UL[i][j];
                curque.add({i, j});
                have[a[i][j]] = 1;
                Que que[3] = {U[i - 1][j], L[i][j - 1], UL[i - 1][j - 1]};
                int pt[3] = {0, 0, 0};

                while(curque.sz <= q) {
                    int v[3];
                    int mn = INF;
                    int idx = -1;
                    rep(b, 0, 3) {
                        v[b] = (pt[b] < que[b].sz ? getdis(que[b].qs[pt[b]], {i, j}) : INF);
                        if(v[b] < mn) mn = v[b], idx = b;
                    }
                    if(mn == INF) break;
                    if(!have[que[idx].qs[pt[idx]].val()]) {
                        curque.add(que[idx].qs[pt[idx]]);
                        have[que[idx].qs[pt[idx]].val()] = 1;
                    }
                    pt[idx]++;
                }
                rep(l, 0, curque.sz) have[curque.qs[l].val()] = 0;

                res[i][j] = min({i, j, (curque.sz == q + 1 ? getdis(curque.qs[q], {i, j}) : INF)});
                fres[res[i][j]]++;
//                cout << i << " " << j << " " << "qsz: " << res[i][j] << endl;
            }
        }
    }
    for (int i = n; i >= 1; i--) fres[i] += fres[i + 1];
    rep(i, 1, n + 1) cout << fres[i] << "\n";



}