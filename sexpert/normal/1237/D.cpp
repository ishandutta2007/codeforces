#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;

struct node {
    int l, r, mn;
    node *left, *right;

    node(int l, int r, vector<int> &v) : l(l), r(r) {
        if(l == r)
            mn = v[l];
        else {
            int m = (l + r)/2;
            left = new node(l, m, v);
            right = new node(m + 1, r, v);
            mn = min(left->mn, right->mn);
        }
    }

    int find(int sl, int ta) {
        if(r < sl || mn > ta)
            return INF;
        if(l == r)
            return r;
        int f = left->find(sl, ta);
        if(f != INF)
            return f;
        return right->find(sl, ta);
    }

    int qry(int rl, int rr) {
        if(r < rl || rr < l)
            return INF;
        if(rl <= l && r <= rr)
            return mn;
        return min(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(3*n), to(2*n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[2*n + i] = v[n + i] = v[i];
    }
    node tree(0, 3*n - 1, v);
    for(int i = 0; i < 2*n; i++)
        to[i] = tree.find(i + 1, (v[i] - 1)/2);
    //for(int i = 0; i < 2*n; i++)
    //    cout << to[i] << " ";
    //cout << endl;
    node tree2(0, 2*n - 1, to);
    for(int i = 0; i < n; i++) {
        int hi = 2*n - 1, lo = 1;
        if(tree2.qry(i, 2*n - 1) == INF) {
            cout << "-1 ";
            continue;
        }
        while(lo < hi) {
            int mi = (lo + hi)/2;
            if(tree2.qry(i, min(i + mi - 1, 2*n - 1)) <= i + mi - 1)
                hi = mi;
            else
                lo = mi + 1;
        }
        cout << lo - 1 << " ";
    }
    cout << endl;
}