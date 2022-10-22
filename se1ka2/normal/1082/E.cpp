#include <functional>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 100000000;

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

int a[500002];
int ca[500002];
vector<int> v[500002];

int main()
{
    int n, c;
    cin >> n >> c;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int cc = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == c) cc++;
        else{
            ca[a[i]]++;
            v[a[i]].push_back(ca[a[i]] - cc);
        }
    }
    int ans = 0;
    for(int i = 0; i < 500002; i++){
        SegmentTree<int> seg((int)v[i].size(), [](int a, int b){return max(a, b);}, -INF);
        for(int j = 0; j < (int)v[i].size(); j++) seg.set(j, v[i][j]);
        seg.build();
        for(int j = 0; j < (int)v[i].size(); j++){
            ans = max(ans, seg.query(j, (int)v[i].size()) - seg[j] + 1);
        }
    }
    cout << ans + cc << endl;
}