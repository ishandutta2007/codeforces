#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 4005, M = 20005;

struct Queue {
    int D[2][N][N];
    pii sx[2][N];
    int sz[2] = {0, 0};

    void add(pii p, int idx) {
        int &Lsz = sz[idx];
        auto L = D[idx];
        auto Lx = sx[idx];
        Lsz++;
        Lx[Lsz] = p;
        memcpy(L[Lsz], L[Lsz - 1], sizeof(L[Lsz]));
        for (int i = N - 1; i >= p.first; i--) L[Lsz][i] = max(L[Lsz][i], L[Lsz][i - p.first] + p.second);
    }

    void pop() {
        if(sz[1] == 0) {
            while(sz[0]) {
                add(sx[0][sz[0]], 1);
                sz[0]--;
            }
        }
        sz[1]--;
    }

    int query(int x) {
        int res = 0;
        rep(i, 0, x + 1) res = max(res, D[1][sz[1]][i] + D[0][sz[0]][x - i]);
        return res;
    }
} que;

struct Qr {
    int x, id;
};

int n, p;
int c[N], h[N], t[N];
int q;
vector<Qr> qr[M];
vi add[M];
int del[M];
int res[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;
    rep(i, 0, n) {
        cin >> c[i] >> h[i] >> t[i];
        add[t[i]].push_back(i);
        del[t[i] + p]++;
    }
    cin >> q;
    rep(i, 0, q) {
        int a, b; cin >> a >> b;
        qr[a].push_back({b, i});
    }
    rep(i, 0, M) {
        for (int idx : add[i]) que.add(pii{c[idx], h[idx]}, 0);
        while(del[i]--) que.pop();
        for (auto &qs : qr[i]) {
            res[qs.id] = que.query(qs.x);
        }
    }
    rep(i, 0, q) cout << res[i] << '\n';

}