#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

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
    int t;
    cin >> t;
    int a[200005];
    int p[200005], s[200005];
    P q[200005];
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int lar = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            lar = max(lar, a[i]);
        }
        int m;
        cin >> m;
        bool able = false;
        for(int i = 0; i < m; i++){
            cin >> p[i] >> s[i];
            if(p[i] >= lar) able = true;
            q[i] = P(s[i], p[i]);
        }
        if(!able){
            cout << -1 << endl;
            continue;
        }
        SegmentTree<int> seg(m, [](int a, int b){return max(a, b);}, 0);
        sort(q, q + m);
//        for(int i = 0; i < m; i++) cout << q[i].first << " " << q[i].second << "      ";
//        cout << endl;
        for(int i = 0; i < m; i++){
            seg.set(i, q[i].second);
        }
        seg.build();
        SegmentTree<int> mst(n, [](int a, int b){return max(a, b);}, 0);
        for(int i = 0; i < n; i++){
            mst.set(i, a[i]);
        }
        int t = 0;
        int ans = 0;
        mst.build();
        while(t < n){
            int now = 131072;
            int mid = now / 2;
            while(mid > 0){
                if(now > n){
                    now -= mid;
                    mid /= 2;
                    continue;
                }
//                cout << now << " ";
                int j = lower_bound(q, q + m, P(now, 0)) - q;
                int mp = seg.query(j, m);
                int ma = mst.query(t, min(n, t + now));
                if(mp >= ma) now += mid;
                else now -= mid;
                mid /= 2;
//                cout << j << " " << mp << " " << ma << " " << endl;
            }
            if(now > n) now--;
            else{
                int j = lower_bound(q, q + m, P(now, 0)) - q;
                int mp = seg.query(j, m);
                int ma = mst.query(t, min(n, t + now));
                if(mp < ma) now--;
            }
//            cout << t << " " << now << endl;
            t += now;
            ans++;
        }
        cout << ans << endl;
    }
}