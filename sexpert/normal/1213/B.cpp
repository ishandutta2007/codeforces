#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct node {
    int l, r, val;
    node *left, *right;
    
    node(int l, int r, vector<int> &v) : l(l), r(r) {
        if(l == r)
            val = v[l];
        else {
            int m = (l + r)/2;
            left = new node(l, m, v);
            right = new node(m + 1, r, v);
            val = min(left->val, right->val);
        }
    }
    
    int qry(int rl, int rr) {
        if(r < rl || rr < l)
            return INF;
        if(rl <= l && r <= rr)
            return val;
        return min(left->qry(rl, rr), right->qry(rl, rr));
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    node tree(0, n - 1, v);
    int ans = 0;
    for(int i = n - 2; i >= 0; i--)
        if(v[i] > tree.qry(i + 1, n - 1))
            ans++;
            
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}