#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++) 
#define f0r(i, a) f1r(i, 0, a)
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

const ll INF = 1e18;
template <class T> struct LazySeg {
    std::vector<T> sum, lazy;
    int sz;
    void init(int sz_) {
        sz = 1;
        while (sz < sz_) sz *= 2;
        sum.assign(2 * sz, 0);
        lazy.assign(2 * sz, 0);
    }
    void push(int ind, int L, int R) {
        sum[ind] += lazy[ind];
        if (L != R) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    void pull(int ind) {
        sum[ind] = max(sum[2 * ind], sum[2 * ind + 1]);
    }
    void build() {
        for (int i = sz - 1; i >= 1; i--) {
            pull(i);
        }
    }
    void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * ind, L, M);
        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
        pull(ind);
    }
    T qmax(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (lo > R || L > hi) return -INF;
        if (lo <= L && R <= hi) return sum[ind];
        int M = (L + R) / 2;
        return max(qmax(lo, hi, 2 * ind, L, M), qmax(lo, hi, 2 * ind + 1, M + 1, R));
    }
};
const int M = 1e6 + 5;
pi ti[M];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    LazySeg<ll> seg;
    seg.init(M);
    f0r(i, M) {
        seg.upd(i, i, i);
    }
    f0r(i, q) {
        char c; cin >> c;
        if (c == '+') {
            int t, d; cin >> t >> d;
            ti[i] = mp(t, d);
            seg.upd(t+1, M-1, -d);
        } else if (c == '-') {
            int id; cin >> id; id--;
            int t = ti[id].f;
            int d = ti[id].s;
            seg.upd(t+1, M-1, d);
        } else {
            int t; cin >> t;
            ll ans = -seg.qmax(t+1, t+1) + (t+1) + seg.qmax(0, t) - t;
            cout << ans << '\n';
        }
    }
    return 0;
}