#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

struct obj {
    ll mn, cnt;
};

obj merge(obj a, obj b) {
    if(a.mn == b.mn)
        return {a.mn, (a.cnt + b.cnt) % MOD};
    if(a.mn < b.mn)
        return {a.mn, a.cnt};
    return {b.mn, b.cnt};
}

struct node {
    int l, r;
    obj stuff;
    node *left, *right;

    node(int _l, int _r) : l(_l), r(_r) {
        if(l == r)
            stuff = {INF, 0};
        else {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int p, obj v) {
        if(r < p || p < l)
            return;
        if(l == r) {
            stuff = v;
            return;
        }
        left->upd(p, v);
        right->upd(p, v);
        stuff = merge(left->stuff, right->stuff);
    }

    obj qry(int rl, int rr) const {
        if(rr < l || r < rl)
            return {INF, 0};
        if(rl <= l && r <= rr)
            return stuff;
        return merge(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<ii> segs;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> y >> x;
        segs.push_back({x, y});
    }
    segs.push_back({0, 0});
    vector<obj> stuffs(n + 1);
    node tree(0, n + 1);
    sort(segs.begin(), segs.end());
    for(int i = n; i >= 0; i--) {
        if(segs[n].first < segs[i].second) {
            stuffs[i] = {segs[i].first, 1};
            //cout << "i = " << i << ": " << segs[i].first << " " << 1 << endl;
            tree.upd(i, stuffs[i]);
            continue;
        }
        int lo = 0, hi = n;
        while(lo < hi) {
            int mi = (lo + hi)/2;
            if(segs[mi].first >= segs[i].second)
                hi = mi;
            else
                lo = mi + 1;
        }
        obj wut = tree.qry(lo, n);
        stuffs[i] = {wut.mn - segs[i].second + segs[i].first, wut.cnt};
        //cout << "i = " << i << ": " << stuffs[i].mn << " " << stuffs[i].cnt << '\n';
        tree.upd(i, stuffs[i]);
    }
    cout << stuffs[0].cnt << '\n';
}