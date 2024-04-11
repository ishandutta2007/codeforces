#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)3e5 + 50;

int n, m, q;
int v[N];
int rv[N], sw[N];
int shad[N];

struct Tree {
    ll dat[N * 4];

    void init_dat(int x, int l, int r){
        if(l == r){dat[x] = v[l]; return ;}

        int mid = (l + r) / 2;
        init_dat(lson(x), l, mid);
        init_dat(rson(x), mid+1, r);
        dat[x] = dat[lson(x)] + dat[rson(x)];
    }

    void update(int bt, int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = val;
            return ;
        }
        if(rv[bt]) {
            pos = l + r - pos;
        }
        if(sw[bt - 1]) {
            if(pos <= mid) pos += (1 << (bt - 1));
            else pos -= (1 << (bt - 1));
        }

        if(pos <= mid) update(bt - 1, pos, lson(x), l, mid, val);
        else update(bt - 1, pos, rson(x), mid+1, r, val);
        dat[x] = dat[lson(x)] + dat[rson(x)];
    }

    ll ask(int bt, int a, int b, int x, int l, int r) {
        assert(l <= a && b <= r);

        if(a <= l && r <= b) return dat[x];
        if(rv[bt]) {
            int na = l + r - b;
            int nb = l + r - a;
            a = na, b = nb;
        }
        ll res = 0;
        int mid = (l + r) / 2;
        int blen = (1 << (bt - 1));
        if(min(b, mid) >= a) {
            res += sw[bt - 1] ? ask(bt - 1, a + blen, min(b, mid) + blen, rson(x), mid + 1, r) :
                                ask(bt - 1, a, min(b, mid), lson(x), l, mid);
        }
        if(max(a, mid + 1) <= b) {
            res += sw[bt - 1] ? ask(bt - 1, max(a, mid + 1) - blen, b - blen, lson(x), l, mid) :
                   ask(bt - 1, max(a, mid + 1), b, rson(x), mid + 1, r);
        }
        return res;
    }
} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> q;
    n = (1 << m);
    rep(i, 0, n) cin >> v[i], shad[i] = v[i];
    tree.init_dat(0, 0, n - 1);
    while(q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int pos, val; cin >> pos >> val; pos--;
            tree.update(m, pos, 0, 0, n - 1, val);
//            shad[pos] = val;
        } else if (tp == 2) {
            int k; cin >> k;
            rv[k] ^= 1;
//            if(k) for(int l = 0; l < n; l += (1 << k)) {
//                for(int i = l, j = l + (1 << k) - 1; i < j; i++, j--) {
//                    swap(shad[i], shad[j]);
//                }
//            }
        } else if(tp == 3) {
            int k; cin >> k;
            sw[k] ^= 1;
//            for(int l = 0; l < n; l += 2 * (1 << k)) {
//                for(int i = l, j = l + (1 << k); i < l + (1 << k); i++, j++) {
//                    swap(shad[i], shad[j]);
//                }
//            }
        } else {
            int l, r; cin >> l >> r; l--, r--;
            cout << tree.ask(m, l, r, 0, 0, n - 1) << '\n';
//            ll sum = 0;
//            rep(i, l, r + 1) sum += shad[i];
//            cout << sum << '\n';
//            assert(sum == tree.ask(m, l, r, 0, 0, n - 1));
//            cout << sum << '\n';
        }
    }

}