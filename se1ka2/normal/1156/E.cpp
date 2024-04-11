#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int p[200005];
int b[200005];
P q[200005];
int r[200005], l[200005];

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
    for(int i = 0; i < n; i++){
        cin >> p[i];
        q[i] = P(p[i], i);
        b[p[i]] = i;
    }
    sort(q, q + n, greater<P>());
    SegmentTree<int> lar(n, [](int a, int b){return max(a, b);}, -1);
    SegmentTree<int> les(n, [](int a, int b){return min(a, b);}, n);
    for(int i = 0; i < n; i++){
        r[q[i].first] = les.query(q[i].second, n) - 1;
        l[q[i].first] = lar.query(0, q[i].second) + 1;
        lar.update(q[i].second, q[i].second);
        les.update(q[i].second, q[i].second);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(r[i] - b[i] < b[i] - l[i]){
            for(int j = b[i] + 1; j <= r[i]; j++){
                if(b[i - p[j]] >= l[i] && b[i - p[j]] < b[i]) ans++;
            }
        }
        else{
            for(int j = l[i]; j < b[i]; j++){
                if(b[i - p[j]] <= r[i] && b[i - p[j]] > b[i]) ans++;
            }
        }
    }
    cout << ans << endl;
}