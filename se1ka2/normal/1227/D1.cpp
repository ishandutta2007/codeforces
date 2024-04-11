#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PP;

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
    int a[100002];
    P p[100002];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        p[i] = P(-a[i], i);
    }
    sort(p, p + n);
    int m;
    cin >> m;
    PP pp[100002];
    for(int i = 0; i < m; i++){
        int k, p;
        cin >> k >> p;
        pp[i] = PP(P(k, p), i);
    }
    sort(pp, pp + m);
    int ans[100002];
    SegmentTree<int> seg(n, [](int a, int b){return a + b;}, 0);
    int l = 0;
    int nn = 1;
    while(nn < n) nn <<= 1;
    for(int i = 0; i < m; i++){
        while(l < pp[i].first.first){
            seg.update(p[l].second, 1);
            l++;
        }
        int now = nn / 2;
        int mid = now / 2;
        while(mid){
            if(seg.query(0, now) < pp[i].first.second){
                now += mid;
            }
            else{
                if(seg.query(0, now) == pp[i].first.second && seg[now - 1] == 1){
                    ans[pp[i].second] = now - 1;
                    break;
                }
                now -= mid;
            }
            mid /= 2;
        }
        if(seg.query(0, now) == pp[i].first.second && seg[now - 1] == 1) ans[pp[i].second] = now - 1;
        else ans[pp[i].second] = nn - 1;
    }
    for(int i = 0; i < m; i++) cout << a[ans[i]] << endl;
}