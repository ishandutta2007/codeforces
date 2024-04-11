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
const int N = (int)2e5 + 50;

int n, q;

struct Qr {
    int tp, l, r, x;
} qrs[N];

int tim[N];
set<int> S;

const int LOGN = 19;

struct P {
    pii s0, s1;
};

P operator + (P a, P b) {
    if(a.s0 > b.s0) return {a.s0, max(a.s1, b.s0)};
    else return {b.s0, max(a.s0, b.s1)};
}

struct RMQ {
    int n;

    P st[LOGN][N];
    int mm[N];


    void build(int _n) {
        n = _n;
        mm[0]=-1;
        for(int i = 1; i <= n; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
        for(int i = 0; i < n; i++){
            st[0][i] = {{tim[i], i}, {-1, -1}};
        }
        for(int lg = 1; lg < LOGN; lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                st[lg][j] = st[lg-1][j] + st[lg-1][j+(1<<(lg-1))];
            }
        }
    }

    P rmq(int l, int r){
        P res = {{-1, -1}, {-1, -1}};
        rep(i, 0, LOGN) {
            if((r - l + 1) >> i & 1) {
                res = res + st[i][l];
                l += (1 << i);
            }
        }
        return res;
    }
} rmq;

int last[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n) S.insert(i);
    fill(tim, tim + n, N);
    fill(last, last + n, N);
    rep(i, 0, q) {
        int tp; cin >> tp;
        if(tp == 0) {
            int l, r, x; cin >> l >> r >> x; l--, r--;
            qrs[i] = {tp, l, r, x};
            if(x == 0) {
                for (auto it = S.lower_bound(l); it != S.end() && *it <= r;) {
                    tim[*it] = i;
                    it = S.erase(it);
                }
            }
        } else {
            int x; cin >> x; x--;
            qrs[i] = {tp, -1, -1, x};
        }
    }
    rmq.build(n);
    rep(i, 0, q) {
        int tp = qrs[i].tp;
        if(tp == 0) {
            if(qrs[i].x == 1) {
                P p = rmq.rmq(qrs[i].l, qrs[i].r);
//                cout << "! " << p.s0.first << ", " << p.s0.second << ", " << p.s1.first << ", " << p.s1.second << endl;
                last[p.s0.second] = min(last[p.s0.second], p.s1.first);
            }
        } else {
            int j = qrs[i].x;
//            cout << "? " << j << " " << tim[j] << " " << last[j] << endl;
            if(tim[j] < i) cout << "NO\n";
            else if(last[j] < i) cout << "YES\n";
            else cout << "N/A" << '\n';
        }
    }

}