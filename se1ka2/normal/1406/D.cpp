#include <functional>
#include <iostream>
using namespace std;
typedef long long ll;

template<typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build() {
        for(int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = f(L, seg[a++]);
            if(b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }
};

int main()
{
    int n;
    cin >> n;
    ll a[100005];
    for(int i = 0; i < n; i++) cin >> a[i];
    SegmentTree<ll> db(n, [](ll a, ll b){return a + b;}, 0ll), dc(n, [](ll a, ll b){return a + b;}, 0ll);
    for(int i = 0; i < n - 1; i++){
        if(a[i] > a[i + 1]) db.set(i, a[i + 1] - a[i]);
        else dc.set(i, a[i + 1] - a[i]);
    }
    db.build();
    dc.build();
    int q;
    cin >> q;
    q++;
    while(q--){
        ll b = db.query(0, n), c = dc.query(0, n);
        ll right = 1000000000000000, left = -1000000000000000;
        while(right - left > 1){
            ll mid = (right + left) / 2;
            if(a[0] - mid + c <= mid && a[n - 1] - mid - b <= mid) right = mid;
            else left = mid;
        }
        cout << right << endl;
        if(q == 0) break;
        int l, r;
        ll x;
        cin >> l >> r >> x;
        l -= 2; r--;
        if(l == -1){
            a[0] += x;
        }
        if(r == n - 1 && r > 0){
            a[n - 1] += x;
        }
        if(l >= 0){
            if(db[l] < 0){
                if(db[l] + x <= 0) db.update(l, db[l] + x);
                else{
                    dc.update(l, db[l] + x);
                    db.update(l, 0);
                }
            }
            else{
                if(dc[l] + x >= 0) dc.update(l, dc[l] + x);
                else{
                    db.update(l, dc[l] + x);
                    dc.update(l, 0);
                }
            }
        }
        if(r < n - 1){
            if(db[r] < 0){
                if(db[r] - x <= 0) db.update(r, db[r] - x);
                else{
                    dc.update(r, db[r] - x);
                    db.update(r, 0);
                }
            }
            else{
                if(dc[r] - x >= 0) dc.update(r, dc[r] - x);
                else{
                    db.update(r, dc[r] - x);
                    dc.update(r, 0);
                }
            }
        }
    }
}