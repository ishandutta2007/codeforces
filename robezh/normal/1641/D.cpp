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
typedef unsigned long long ull;
const int N = (int)1e5 + 50, M = 5, NM = N * M;
const int INF = (int)2e9 + 50;

struct Arr {
    int a[M], w;
} p[N];

ull has[NM];

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) {
        rep(j, 0, m) cin >> p[i].a[j];
        cin >> p[i].w;
    }
    sort(p, p + n, [](const Arr &a0, const Arr &a1) {
        return a0.w < a1.w;
    });
    vi vs;
    rep(i, 0, n) rep(j, 0, m) vs.push_back(p[i].a[j]);
    sort(all(vs));
    vs.resize(unique(all(vs)) - vs.begin());
    rep(i, 0, n) {
        rep(j, 0, m) p[i].a[j] = lower_bound(all(vs), p[i].a[j]) - vs.begin();
    }
    int res = INF;
    for (int i = 0; i < n; i += 64) {
        for (int j = i, d = 0; j < min(i + 64, n); j++, d++) {
            ull mask = 0;
            rep(l, 0, m) mask |= has[p[j].a[l]];
            rep(k, 0, d) {
                if(!(mask >> k & 1)) res = min(res, p[j].w + p[i + k].w);
            }
            rep(l, 0, m) has[p[j].a[l]] |= (1ULL << d);
        }
        for (int j = i + 64; j < n; j++) {
            ull mask = 0;
            rep(l, 0, m) mask |= has[p[j].a[l]];
            if(~mask) {
                res = min(res, p[j].w + p[i + (int)(__builtin_ctzll(~mask))].w);
            }
        }

        for (int j = i, d = 0; j < min(i + 64, n); j++, d++) {
            rep(l, 0, m) has[p[j].a[l]] = 0;
        }
    }

    if(res == INF) cout << -1 << '\n';
    else cout << res << '\n';

}