#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

struct node {
    int l, r, v;
    node *left, *right;

    node(int _l, int _r) : l(_l), r(_r), v(0), left(nullptr), right(nullptr) {}

    void upd(int p, int _v) {
        if(r < p || p < l)
            return;
        if(l == r) {
            v = _v;
            return;
        }
        int mi = (l + r)/2;
        if(p <= mi) {
            if(!left)
                left = new node(l, mi);
            left->upd(p, _v);
            v = left->v;
        }
        else {
            if(!right)
                right = new node(mi + 1, r);
            right->upd(p, _v);
            v = right->v;
        }
        if(left && right)
            v = max(left->v, right->v);
    }

    int find(int rl, int rr, int bn) {
        assert(this);
        if(rl > rr || rr < l || r < rl || v < bn)
            return 0;
        if(l == r)
            return l;
        int mi = (l + r)/2;
        if(!right)
            right = new node(mi + 1, r);
        int x = right->find(rl, rr, bn);
        if(x)
            return x;
        if(!left)
            left = new node(l, mi);
        return left->find(rl, rr, bn);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    node hoz(1, n), ver(1, n);
    set<pair<int, int>> qd;
    while(q--) {
        int x, y;
        char t;
        cin >> x >> y >> t;
        if(qd.count({x, y})) {
            cout << "0\n";
            continue;
        }
        qd.insert({x, y});
        if(t == 'U') {
            int ro = hoz.find(1, y - 1, y);
            cout << y - ro << '\n';
            ver.upd(x, x + y - ro - 1);
        }
        else {
            int co = ver.find(1, x - 1, x);
            cout << x - co << '\n';
            hoz.upd(y, x + y - co - 1);
        }
    }
}