#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MAX = 1e6 + 10;
const int INF = 1e9;
int prime[MAX], dp[MAX];

struct node {
    int l, r, mn;
    node *left, *right;

    node(int l, int r) : l(l), r(r), mn(INF) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int p, int v) {
        if(r < p || p < l) return;
        if(l == r) {
            mn = v;
            return;
        }
        left->upd(p, v);
        right->upd(p, v);
        mn = min(left->mn, right->mn);
    }

    int qry(int rl, int rr) {
        if(rr < l || r < rl)
            return INF;
        if(rl <= l && r <= rr)
            return mn;
        return min(left->qry(rl, rr), right->qry(rl, rr));
    }
};

void sieve() {
    for(int p = 2; p < MAX; p++) {
        if(prime[p]) continue;
        for(int q = p; q < MAX; q += p)
            prime[q] = p;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    node tree(1, MAX);
    sieve();
    for(int i = 3; i < MAX; i++) {
        if(i == prime[i])
            tree.upd(i, i);
        else
            tree.upd(i, i - prime[i] + 1);
    }
    int q;
    cin >> q;
    cout << min(q - prime[q] + 1, tree.qry(q - prime[q] + 1, q)) << '\n';
}