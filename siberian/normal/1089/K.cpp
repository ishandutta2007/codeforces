#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define ll long long

using namespace std;

const int MAXN = 1e6 + 10;

struct node {
    int l = -1;
    int r = -1;
    ll S = 0; //sum on prefix
    ll val = 0; //i - pref[i-1]
    ll lval = 0;
    node() {}
};

node pool[4 * MAXN];
int pt = 0;

int build(int L, int R) {
    node A;
    if (L == R - 1){
        A.val = L;
        pool[pt] = A;
        pt++;
        return pt - 1;
    }
    int M = (L + R) / 2;
    A.l = build(L, M);
    A.r = build(M, R);
    A.val = max(pool[A.l].val, pool[A.r].val);
    pool[pt] = A;
    pt++;
    return pt - 1;
}

void relax(int root) {
    int L = pool[root].l, R = pool[root].r;
    pool[root].S = pool[L].S + pool[R].S;
    pool[root].val = max(pool[L].val, pool[R].val);
}

void push(int root) {
    int L = pool[root].l, R = pool[root].r;
    ll more = pool[root].lval;
    pool[L].val += more;
    pool[L].lval += more;
    pool[R].val += more;
    pool[R].lval += more;
    pool[root].lval = 0;
}

void upd_val(int root, int L, int R, int l, int r, ll x) {
    if (L == l && R == r) {
        pool[root].val += x;
        pool[root].lval += x;
        return;
    }
    int M = (L + R) / 2;
    push(root);
    if (l < M) {
        upd_val(pool[root].l, L, M, l, min(M, r), x);
    }
    if (r > M) {
        upd_val(pool[root].r, M, R, max(l, M), r, x);
    }
    relax(root);
}

void upd_s(int root, int L, int R, int ind, ll x) {
    if (L == R - 1) {
        pool[root].S += x;
        return;
    }
    push(root);
    int M = (L + R) / 2;
    if (ind < M) {
        upd_s(pool[root].l, L, M, ind, x);
    } else {
        upd_s(pool[root].r, M, R, ind, x);
    }
    relax(root);
}

ll get_val(int root, int L, int R, int l, int r) {
    if (L == l && R == r) {
        return pool[root].val;
    }
    push(root);
    int M = (L + R) / 2;
    ll val1 = 0, val2 = 0;
    if (l < M)
        val1 = get_val(pool[root].l, L, M, l, min(M, r));
    if (r > M)
        val2 = get_val(pool[root].r, M, R, max(l, M), r);
    return max(val1, val2);
}

ll get_s(int root, int L, int R, int l, int r) {
    if (L == l && R == r) {
        return pool[root].S;
    }
    push(root);
    int M = (L + R) / 2;
    ll s1 = 0, s2 = 0;
    if (l < M)
        s1 = get_s(pool[root].l, L, M, l, min(M, r));
    if (r > M)
        s2 = get_s(pool[root].r, M, R, max(l, M), r);
    return s1 + s2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int root = build(0, MAXN);
    int q;
    cin >> q;
    vector<pair<ll, ll>> kn(q);
    for (int j = 0; j < q; ++j){
        char tp;
        cin >> tp;
        if (tp == '?') {
            ll T;
            cin >> T;
            ll val = get_val(root, 0, MAXN, 0, T + 1);
            ll S = get_s(root, 0, MAXN, 0, T + 1);
            //cerr << val << " " << " " << S << "\n";
            ll go = max(T, val + S);
            //cerr << "!";
            cout << go - T << "\n";
            continue;
        }
        if (tp == '+') {
            ll t, d;
            cin >> t >> d;
            kn[j] = { t, d };
            upd_s(root, 0, MAXN, t, d);
            upd_val(root, 0, MAXN, t + 1, MAXN, -d);

        }
        if (tp == '-') {
            int ind;
            cin >> ind;
            ind--;
            ll t = kn[ind].first, d = kn[ind].second;
            upd_s(root, 0, MAXN, t, -d);
            upd_val(root, 0, MAXN, t + 1, MAXN, d);
        }
    }
}
//*/