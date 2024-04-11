#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int l, r, v;
    node *left, *right;

    node(int l, int r) : l(l), r(r), v(0) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    };

    void upd(int p, int u) {
        if(r < p || p < l) return;
        if(l == r) {
            v += u;
            return;
        }
        left->upd(p, u);
        right->upd(p, u);
        v = left->v + right->v;
    }

    int find(int rl, int rr) {
        if(rr < l || r < rl || v == 0) return -1;
        if(l == r) return l;
        int x = right->find(rl, rr);
        if(x != -1)
            return x;
        return left->find(rl, rr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    node tree(1, k);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.upd(x, 1);
    }
    vector<int> v(k);
    for(auto &x : v)
        cin >> x;
    v.push_back(0);
    reverse(v.begin(), v.end());
    int cur = 0;
    vector<int> seq;
    for(int i = 1; i <= k; i++) {
        if(v[i] > v[i - 1]) {
            while(cur < v[i]) {
                seq.push_back(k - i + 1);
                cur++;
            }
        }
    }
    /*for(auto s : seq)
        cout << s << " ";
    cout << endl;*/
    vector<vector<int>> res;
    int used = 0;
    while(used < n) {
        vector<int> cur;
        for(auto s : seq) {
            int sz = tree.find(1, s);
            if(sz == -1)
                break;
            tree.upd(sz, -1);
            cur.push_back(sz);
            used++;
        }
        res.push_back(cur);
    }
    cout << res.size() << '\n';
    for(auto vc : res) {
        cout << vc.size() << " ";
        for(auto x : vc)
            cout << x << " ";
        cout << '\n';
    }
}