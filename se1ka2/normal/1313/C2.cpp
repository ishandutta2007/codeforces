#include <functional>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const int INF = 1000000003;

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

ll m[500005], l[500005], r[500005];
ll last[500005];
P p[500005];
ll ans[500005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m[i];
        p[i] = P(m[i], i);
    }
    sort(p, p + n);
    SegmentTree<int> seg1(n, [](int a, int b){return max(a, b);}, 0);
    for(int i = 0; i < n; i++){
        last[p[i].second] = seg1.query(0, p[i].second) - 1;
        seg1.update(p[i].second, p[i].second + 1);
    }
    for(int i = 1; i < n; i++){
        if(last[i - 1] == -1) l[i] = m[i - 1] * i;
        else l[i] = l[last[i - 1] + 1] + m[i - 1] * ((i - 1) - last[i - 1]);
    }
    for(int i = 0; i < n; i++) p[i] = P(p[i].first, -p[i].second);
    sort(p, p + n);
    SegmentTree<int> seg2(n, [](int a, int b){return min(a, b);}, INF);
    for(int i = 0; i < n; i++){
        last[-p[i].second] = seg2.query(-p[i].second, n);
        seg2.update(-p[i].second, -p[i].second);
    }
    for(int i = n - 2; i >= 0; i--){
        if(last[i + 1] == INF) r[i] = m[i + 1] * (n - i - 1);
        else r[i] = r[last[i + 1] - 1] + m[i + 1] * (last[i + 1] - (i + 1));
    }
    ll lar = 0;
    int al = -1;
    for(int i = 0; i < n; i++){
        if(i > 0 && m[i - 1] > m[i]) continue;
        if(i < n - 1 && m[i + 1] > m[i]) continue;
        if(l[i] + m[i] + r[i] > lar){
            lar = l[i] + m[i] + r[i];
            al = i;
        }
    }
    ans[al] = m[al];
    for(int i = al - 1; i >= 0; i--) ans[i] = min(ans[i + 1], m[i]);
    for(int i = al + 1; i < n; i++) ans[i] = min(ans[i - 1], m[i]);
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}