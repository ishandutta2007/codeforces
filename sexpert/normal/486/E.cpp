#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

const ll MOD = 998244853;

ii merge(ii a, ii b) {
    if(a.first > b.first)
        return a;
    if(a.first < b.first)
        return b;
    return {a.first, (a.second + b.second) % MOD};
}

struct node {
    int l, r;
    ii val;
    node *left, *right;

    node(int l, int r) : l(l), r(r) {
        if(l == r) {
            if(l)
                val = {-1, 0};
            else
                val = {0, 1};
        }
        else {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
            val = merge(left->val, right->val);
        }
    }

    ii qry(int rl, int rr) {
        if(rr < l || r < rl)
            return {-1, 0};
        if(rl <= l && r <= rr)
            return val;
        return merge(left->qry(rl, rr), right->qry(rl, rr));
    }
    void upd(int p, ii v) {
        if(r < p || p < l)
            return;
        if(l == r) {
            val = merge(v, val);
            return;
        }
        left->upd(p, v);
        right->upd(p, v);
        val = merge(left->val, right->val);
    }
};

vector<ii> liscnt(vector<int> v) {
    node tree(0, 100000);
    int n = v.size();
    vector<ii> result(n);
    for(int i = 0; i < n; i++) {
        ii p = tree.qry(0, v[i] - 1);
        p.first++;
        result[i] = p;
        tree.upd(v[i], p);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    auto v1 = liscnt(v);
    int lislen = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++)
        lislen = max(lislen, (int)v1[i].first);
    for(int i = 0; i < n; i++) {
        if(v1[i].first == lislen)
            cnt = (cnt + v1[i].second) % MOD;
    }
    reverse(v.begin(), v.end());
    transform(v.begin(), v.end(), v.begin(), [](int a) -> int { return 100001 - a; });
    auto v2 = liscnt(v);
    reverse(v2.begin(), v2.end());
    //for(int i = 0; i < n; i++)
    //    cout << i << " " << v1[i].first << " " << v1[i].second << " " << v2[i].first << " " << v2[i].second << '\n';
    //cout << lislen << " " << cnt << endl;
    for(int i = 0; i < n; i++) {
        if(v1[i].first + v2[i].first != lislen + 1) {
            cout << "1";
            continue;
        }
        ll tot = (v1[i].second * v2[i].second) % MOD;
        cout << (tot == cnt ? "3" : "2");
    }
    cout << '\n';
}