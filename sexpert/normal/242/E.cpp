#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int l, r, sum;
    node *left, *right;
    bool swap;

    inline int getsum() { return swap ? r - l + 1 - sum : sum; }
    inline void merge() { sum = left->getsum() + right->getsum(); }
    inline void compose() { swap = swap ? false : true; }
    void push() {
        if(swap) {
            left->compose();
            right->compose();
            swap = false;
        }
    }

    node(int l, int r, int *A) : l(l), r(r), swap(false) {
        if(l == r)
            sum = A[l];
        else {
            int m = (l + r)/2;
            left = new node(l, m, A);
            right = new node(m + 1, r, A);
            merge();
        }
    }

    int qry(int rl, int rr) {
        if(rr < l || r < rl) return 0;
        if(rl <= l && r <= rr) return getsum();
        push();
        merge();
        return left->qry(rl, rr) + right->qry(rl, rr);
    }

    void upd(int rl, int rr) {
        if(rr < l || r < rl) return;
        if(rl <= l && r <= rr) { compose(); return; }
        push();
        left->upd(rl, rr);
        right->upd(rl, rr);
        merge();
    }
};

const int MAXN = 1e5 + 5;
int A[20][MAXN];
node* tree[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for(int l = 0; l < 20; l++)
            A[l][i] += ((x & (1 << l)) ? 1 : 0);
    }
    for(int lv = 0; lv < 20; lv++)
        tree[lv] = new node(1, n, A[lv]);
    int q;
    cin >> q;
    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1) {
            ll x, ans = 0;
            for(int lv = 0; lv < 20; lv++) {
                x = tree[lv]->qry(l, r);
                ans += (x*(1ll << lv));
            }
            cout << ans << '\n';
        }
        if(t == 2) {
            int x;
            cin >> x;
            for(int lv = 0; lv < 20; lv++) {
                if(x & (1 << lv))
                    tree[lv]->upd(l, r);
            }
        }
    }
}