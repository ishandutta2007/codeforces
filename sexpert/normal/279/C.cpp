#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 10;
int a[MAXN];
int prv[MAXN], nxt[MAXN];

struct node {
    int l, r, v;
    node *left, *right;

    node(int l, int r) : l(l), r(r) {
        if(l == r)
            v = l;
        else {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
            if(a[left->v] >= a[right->v])
                v = left->v;
            else
                v = right->v;
        }
    }

    int qry(int rl, int rr) {
        if(rr < l || r < rl)
            return -1;
        if(rl <= l && r <= rr)
            return v;
        int L = left->qry(rl, rr), R = right->qry(rl, rr);
        if(L == -1)
            return R;
        if(R == -1)
            return L;
        if(a[L] >= a[R])
            return L;
        return R;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    stack<int> st;
    prv[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] >= a[i - 1])
            prv[i] = prv[i - 1];
        else
            prv[i] = i;
    }
    nxt[n] = n;
    for(int i = n - 1; i >= 1; i--) {
        if(a[i] >= a[i + 1])
            nxt[i] = nxt[i + 1];
        else
            nxt[i] = i;
    }
    node tree(1, n);
    while(m--) {
        int l, r;
        cin >> l >> r;
        int ps = tree.qry(l, r);
        cout << ((prv[ps] <= l && nxt[ps] >= r) ? "Yes" : "No") << '\n';
    }
}