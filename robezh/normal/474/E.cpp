#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
const int N = (int)1e5 + 500;

struct P{
    ll h;
    int i;
    bool operator < (const P &o) const {
        return h < o.h;
    }

    struct less_than {
        bool operator()(const P &a, const P &b) {
            return a.h < b.h;
        }
    };
};

int n, d;
P p[N];
ll h[N];
P dat[N * 4];
int pv[N];

P max(P p1, P p2) {
    return p1.h > p2.h ? p1 : p2;
}

void update(int pos, int x, int l, int r, P p){
    if(r < pos || pos < l) return ;
    int mid = (l + r) / 2;
    if(l == r) {
        dat[x] = max(dat[x], p);
        return ;
    }
    update(pos, lson(x), l, mid, p);
    update(pos, rson(x), mid+1, r, p);

    dat[x] = max(dat[lson(x)], dat[rson(x)]);
}

P query(int a, int b, int x, int l, int r){
    if(r < a || b < l) return P{-1, -1};

    int mid = (l + r) / 2;
    if(a <= l && r <= b) return dat[x];

    P LHS = query(a, b, lson(x), l, mid);
    P RHS = query(a, b, rson(x), mid+1, r);

    return max(LHS, RHS);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
        p[i].h = h[i];
        p[i].i = i;
    }
    sort(p, p + n);
    for(int i = 0; i < n; i++) {
        P mx; mx.h = 0; mx.i = 0;
        int lb = upper_bound(p, p + n, P{h[i] - d, N}, P::less_than()) - p;
        if(lb - 1 >= 0) mx = query(0, lb - 1, 0, 0, n-1);
        int rb = lower_bound(p, p + n, P{h[i] + d, N}, P::less_than()) - p;
        if(rb <= n-1) mx = max(mx, query(rb, n-1, 0, 0, n-1));

        int loc = lower_bound(p, p + n, P{h[i], N}, P::less_than()) - p;
        update(loc, 0, 0, n-1, {mx.h + 1, i});
        pv[i] = mx.i;
    }
    P pres = query(0, n-1, 0, 0, n-1);
    ll cnt = pres.h;
    int la = pres.i;
    vector<int> vals;
    for(int i = 0; i < cnt; i++) {
        vals.push_back(la);
        la = pv[la];
    }
    reverse(vals.begin(), vals.end());
    cout << cnt << endl;
    for(int x : vals) cout << x + 1 << " ";



}