#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int, 60> obj;

obj primitive(int t) {
    obj res;
    for(int i = 0; i < 60; i++)
        res[i] = ((i % t) ? 1 : 2);
    return res;
}

obj merge(obj A, obj B) {
    obj res;
    for(int i = 0; i < 60; i++)
        res[i] = A[i] + B[(i + A[i]) % 60];
    return res;
}

struct node {
    int l, r;
    obj times;
    node *left, *right;

    node(int l, int r, vector<int> &v) : l(l), r(r) {
        if(l == r)
            times = primitive(v[l]);
        else {
            int mi = (l + r) / 2;
            left = new node(l, mi, v);
            right = new node(mi + 1, r, v);
            times = merge(left->times, right->times);
        }
    }

    void upd(int p, int v) {
        //cout << l << ", " << r << endl;
        if(r < p || p < l) return;
        if(l == r) {times = primitive(v); return;}
        left->upd(p, v);
        right->upd(p, v);
        times = merge(left->times, right->times);
    }

    obj qry(int rl, int rr) {
        if(rl <= l && r <= rr) return times;
        int mi = (l + r) / 2;
        if(rr <= mi) return left->qry(rl, rr);
        if(rl >= mi + 1) return right->qry(rl, rr);
        return merge(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    node tree(0, n - 1, a);
    int q;
    cin >> q;
    while(q--) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c == 'C')
            tree.upd(x - 1, y);
        else
            cout << (tree.qry(x - 1, y - 2))[0] << '\n';
    }
}