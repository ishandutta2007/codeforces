#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

struct node {
    int l, r;
    ll su, lr, la;
    node *left, *right;

    ll get() {
        return ((lr ? 0 : su) + la * (r - l + 1)) % MOD; 
    }
    void merge() {
        su = (left->get() + right->get()) % MOD;
    }
    void push() {
        if(lr) {
            left->lr = 1;
            left->la = 0;
            right->lr = 1;
            right->la = 0;
        }
        left->la = (left->la + la) % MOD;
        right->la = (right->la + la) % MOD;
        lr = la = 0;
    }

    node(int l, int r) : l(l), r(r), su(0), la(0), lr(0) {
        if(l < r) {
            int m = (l + r) / 2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void reset(int rl, int rr) {
        if(r < rl || rr < l) return;
        if(rl <= l && r <= rr) {
            lr = 1;
            la = 0;
            return;
        }
        push();
        left->reset(rl, rr);
        right->reset(rl, rr);
        merge();
    }

    void upd(int rl, int rr, ll v) {
        if(rl > rr || r < rl || rr < l) return;
        if(rl <= l && r <= rr) {
            la = (la + v) % MOD;
            return;
        }
        push();
        left->upd(rl, rr, v);
        right->upd(rl, rr, v);
        merge();
    }

    ll qry(int rl, int rr) {
        if(rr < l || r < rl) return 0;
        if(rl <= l && r <= rr) return get();
        push();
        merge();
        return (left->qry(rl, rr) + right->qry(rl, rr)) % MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int cnt1 = 0;
    for(auto c : s)
        cnt1 += (c == '1');
    if(cnt1 == 0) {
        cout << s.size() << '\n';
        return 0;
    }
    ll mul = 1;
    ll tmp = 1;
    while(s.back() == '0') {
        tmp++;
        s.pop_back();
    }
    mul = (mul * tmp) % MOD;
    reverse(s.begin(), s.end());
    tmp = 1;
    while(s.back() == '0') {
        tmp++;
        s.pop_back();
    }
    mul = (mul * tmp) % MOD;
    if(cnt1 == 1) {
        cout << mul << '\n';
        return 0;
    }
    vector<ll> dp(cnt1);
    dp[0] = 1;
    int ptr = 0;
    tmp = 0;
    ll pv = 0;
    //reverse(s.begin(), s.end());
    //cout << s << '\n';
    int sz = s.size();
    node tree(0, sz);
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == '0') {
            tmp++;
            continue;
        }
        //cout << tmp << '\n';
        ptr++;
        dp[ptr] = ((tmp + 1) * dp[ptr - 1]) % MOD;
        if(tmp > 0)
            dp[ptr] = (dp[ptr] + tree.qry(0, tmp - 1)) % MOD;
        tree.upd(tmp, sz, dp[ptr - 1]);
        //cout << "cuteified [" << pv << ", " << sz << "] with " << dp[ptr - 1] << '\n';
        tree.reset(0, tmp - 1);
        //cout << "fucked!!! [0" << " " << pv - 1 << "]\n";
        pv = tmp;
        tmp = 0;
    }
    //for(int i = 0; i < cnt1; i++)
    //    cout << dp[i] << " ";
    //cout << '\n';
    ll res = 0;
    for(auto x : dp)
        res = (res + x) % MOD;
    cout << (res * mul) % MOD << '\n';
}