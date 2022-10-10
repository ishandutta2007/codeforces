#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAXN = 5e5 + 3;
int n, q, val[MAXN], ans[MAXN];
vi fix[MAXN];

int solve(vi v) {
    int x = 0;
    for(auto m : v)
        x = max(x, x ^ m);
    return x;
}

void gauss(vi &v, int x) {
    for(int i = 0; i < 20; i++) {
        if(x == 0)
            break;
        if(v[i] == 0) {
            v[i] = x;
            break;
        }
        x = min(x, x ^ v[i]);
    }
}

vi merge(vi &v1, vi &v2) {
    vi v = v1;
    for(auto x : v2)
        gauss(v, x);
    return v;
}

void calc(int lo, int hi, vector<pair<ii, int>> &qry) {
    if(hi - lo < 2) {
        for(auto q : qry) {
            vi v(20);
            gauss(v, val[q.first.first]);
            gauss(v, val[q.first.second]);
            ans[q.second] = solve(v);
        }
        return;
    }
    int mi = (lo + hi)/2;
    fix[mi] = vi(20);
    gauss(fix[mi], val[mi]);
    for(int i = mi - 1; i >= lo; i--) {
        fix[i] = fix[i + 1];
        gauss(fix[i], val[i]);
    }
    for(int i = mi + 1; i <= hi; i++) {
        fix[i] = fix[i - 1];
        gauss(fix[i], val[i]);
    }
    vector<pair<ii, int>> left, right;
    for(auto q : qry) {
        if(q.first.first > mi) {
            right.push_back(q);
            continue;
        }
        if(q.first.second < mi) {
            left.push_back(q);
            continue;
        }
        ans[q.second] = solve(merge(fix[q.first.first], fix[q.first.second]));
    }
    qry.clear();
    calc(lo, mi - 1, left);
    calc(mi + 1, hi, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    cin >> q;
    vector<pair<ii, int>> qry;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        qry.emplace_back(ii{l, r}, i);
    }
    calc(1, n, qry);
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}