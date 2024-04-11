#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define x first
#define y second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9 + 12;

struct domino {
    int x, h, id;

    domino() {}
    domino(int x, int h, int id) : x(x), h(h), id(id) {}
};

bool cmp(domino o1, domino o2) {
    return o1.x < o2.x;
}

struct seg_tree {
    vector<int> t;

    void update(int v, int tl, int tr, int ind, int x){
        if(tr - tl == 1) t[v] = x; else{
            int tm = (tl + tr) / 2;
            if(ind < tm)update(2 * v, tl, tm, ind, x); else update(2 * v + 1, tm, tr, ind, x);
            t[v] = max(t[2 * v], t[2 * v + 1]);
        }
    }

    int get_max(int v, int tl, int tr, int l, int r){
        if(tl >= r || tr <= l)return -inf;
        if(tl >= l && tr <= r)return t[v];
        int tm = (tl + tr) / 2;
        return max(get_max(2 * v, tl, tm, l, r), get_max(2 * v + 1, tm, tr, l, r));
    }

    seg_tree() {}
    seg_tree(int n) : t(4 * n, -inf) {}
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<domino> d(n);
    for(int i = 0; i < n; ++i) {
        cin >> d[i].x >> d[i].h;
        d[i].id = i;
    }
    sort(all(d), cmp);
    seg_tree st(n);
    for(int i = n - 1; i >= 0; --i) {
        int l = i, r = n;
        while(r - l > 1) {
            int m = (l + r) / 2;
            if(d[m].x < d[i].x + d[i].h) l = m; else r = m;
        }
        int cur = max(i, st.get_max(1, 0, n, i, r));
        st.update(1, 0, n, i, cur);
    }
    vector<int> ans(n);
    for(int i = 0; i < n; ++i) ans[d[i].id] = st.get_max(1, 0, n, i, i + 1) - i + 1;
    for(auto x : ans)cout << x << " ";
    return 0;
}