#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int MAX = 1e6 + 10;

struct node {
    int l, r;
    ll v;
    node *left, *right;
    
    node(int _l, int _r) : l(_l), r(_r), v(-INF) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }
    
    void upd(int p, ll _v) {
        if(r < p || p < l) return;
        if(l == r) { v = _v; return; }
        left->upd(p, _v);
        right->upd(p, _v);
        v = max(left->v, right->v);
    }
    
    ll qry(int rl, int rr) {
        if(rr < l || r < rl) return -INF;
        if(rl <= l && r <= rr) return v;
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }
};

ll dp[MAX];
int lf_M[MAX], lf_m[MAX], a[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    a[0] = INF;
    vector<int> vM, vm;
    vM.push_back(0);
    vm.push_back(0);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        while(a[i] > a[vM.back()])
            vM.pop_back();
        lf_M[i] = vM.back();
        vM.push_back(i);
        while(a[i] < a[vm.back()] && vm.back() != 0)
            vm.pop_back();
        lf_m[i] = vm.back();
        vm.push_back(i);
    }
    
    node tree1(0, n), tree2(0, n);
    tree1.upd(0, -a[1]);
    tree2.upd(0, a[1]);
    for(int i = 1; i <= n; i++) {
        dp[i] = a[i] + tree1.qry(lf_M[i], i - 1);
        dp[i] = max(dp[i], tree2.qry(lf_m[i], i - 1) - a[i]);
        tree1.upd(i, dp[i] - a[i + 1]);
        tree2.upd(i, dp[i] + a[i + 1]);
    }
    
    cout << dp[n] << '\n';
}