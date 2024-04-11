#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;
ll psum1[MAXN], psum2[MAXN];
ll a, b, c, d, start, len;
int n;
vector<int> times;
set<ll> posit;

struct node {
    int l, r;
    node *left, *right;
    ll mn;

    node(int l, int r, ll* A) : l(l), r(r) {
        if(l == r)
            mn = A[l];
        else {
            int m = (l + r) / 2;
            left = new node(l, m, A);
            right = new node(m + 1, r, A);
            mn = min(left->mn, right->mn);
        }
    }

    ll qry(int rl, int rr) {
        if(rl > rr || rr < l || r < rl)
            return 0;
        if(rl <= l && r <= rr)
            return mn;
        return min(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int bnd(int ti) {
    if(ti <= 0)
        return 0;
    int lo = 0, hi = n;
    while(lo < hi) {
        int mi = (lo + hi + 1) / 2;
        if(times[mi] < ti)
            lo = mi;
        else
            hi = mi - 1;
    }
    return lo;
}

int main() {
    cin >> n >> a >> b >> c >> d >> start >> len;
    times.push_back(0);
    posit.insert(0);
    for(int i = 1; i <= n; i++) {
        int ti, tp;
        cin >> ti >> tp;
        times.push_back(ti);
        if(ti > len)
            posit.insert(ti - len + 1);
        posit.insert(ti + 1);
        psum1[i] = psum1[i - 1] + (tp ? a : -b);
        psum2[i] = psum2[i - 1] + (tp ? c : -d);
    }
    node tree1(0, n, psum1), tree2(0, n, psum2);
    auto good = [&](int p) {
        int id1 = bnd(p), id2 = bnd(p + len);
        if(start + tree1.qry(0, id1) < 0)
            return false;
        ll res = start + psum1[id1] + tree2.qry(id1 + 1, id2) - psum2[id1];
        return (res >= 0);
    };
    for(auto p : posit) {
        if(good(p)) {
            cout << p << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}