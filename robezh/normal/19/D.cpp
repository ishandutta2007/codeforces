#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef pair<int, int> pii;
typedef pair<pii, int> P;
typedef vector<int> vi;
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
typedef long long ll;
const int N = (int)2e5 + 50, INF = (int)1e9 + 50;

#define lson(x) 2*x+1
#define rson(x) 2*x+2


struct Tree {
    int mx[N * 4];

    void init() {
        fill(mx, mx + N * 4, -INF);
    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            mx[x] = val;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        mx[x] = max(mx[lson(x)], mx[rson(x)]);
    }

    int get_above(int x, int l, int r, int val) {
        if(l == r) return l;
        int mid = (l + r) / 2;
        if(mx[lson(x)] >= val) {
            return get_above(lson(x), l, mid, val);
        } else {
            return get_above(rson(x), mid + 1, r, val);
        }
    }

    int query(int a, int b, int x, int l, int r, int val){
        if(r < a || b < l) return -1;
        int mid = (l + r) / 2;
        if(a <= l && r <= b) {
            if(mx[x] < val) return -1;
            return get_above(x, l, r, val);
        };
        auto res = query(a, b, lson(x), l, mid, val);
        if(res != -1) return res;
        else return query(a, b, rson(x), mid+1, r, val);
    }
} tree;

int q;

struct Qr {
    int tp, x, y;
} qr[N];

map<pii, int> ids;

int getid(pii p) {
    auto it = ids.find(p);
    if(it == ids.end()) ids[p] = sz(ids);
    return ids[p];
}

vector<pii> xs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    tree.init();
    cin >> q;
//    q = 200000;
    rep(i, 0, q) {
        string s; int x, y;
        cin >> s >> x >> y;

//        if(i < q / 2) s = "add", x = i, y = i;
//        else s = "remove", x = i, y = q - 1 - i;

        int tp = 0;
        if(s == "remove") tp = 1;
        else if(s == "find") tp = 2;
        qr[i] = {tp, x, y};
        xs.push_back({x, y});
    }
    sort(all(xs));
    xs.resize(unique(all(xs)) - xs.begin());

    rep(i, 0, q) {
        Qr &qs = qr[i];
        if(qs.tp == 2) {
            int loc = (lower_bound(all(xs), pii{qs.x, INF}) - xs.begin());
            auto idx = tree.query(loc, sz(xs) - 1, 0, 0, sz(xs) - 1, qs.y + 1);
            if(idx == -1) cout << -1 << "\n";
            else cout << xs[idx].first << " " << xs[idx].second << "\n";
        } else {
            int loc = (lower_bound(all(xs), pii{qs.x, qs.y}) - xs.begin());
            tree.update(loc, 0, 0, sz(xs) - 1, qs.tp == 0 ? qs.y : -INF);
        }
    }

}