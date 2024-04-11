#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

struct frog {
    ll l, r;
    int idx;
    frog(ll l, ll r, int idx) : l(l), r(r), idx(idx) {}
    bool operator< (const frog &o) const {
        return l < o.l;
    }
};

const int MAXN = 2e5 + 10;
ll x[MAXN], len[MAXN], win[MAXN], n, m;
set<frog> frogs, inverted;
multiset<ii> mos;

void insert_frog(ll l, ll r, int idx) {
    frogs.insert({l, r, idx});
    auto it = frogs.find({l, r, idx});
    assert(it != frogs.end());
    vector<frog> kill;
    while(true) {
        ++it;
        if(it == frogs.end())
            break;
        if(it->r > r)
            break;
        else
            kill.push_back(*it);
    }
    for(auto f : kill) {
        frogs.erase(f);
        inverted.erase({f.r, f.l, f.idx});
    }
    inverted.insert({r, l, idx});
}

bool eat(int idx) {
    auto it = mos.lower_bound({x[idx], 0});
    if(it == mos.end())
        return false;
    if(it->first > x[idx] + len[idx])
        return false;
    int del = it->second;
    mos.erase(it);
    frogs.erase({x[idx], x[idx] + len[idx], idx});
    inverted.erase({x[idx] + len[idx], x[idx], idx});
    len[idx] += del;
    win[idx]++;
    insert_frog(x[idx], x[idx] + len[idx], idx);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> len[i];
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b){ return x[a] > x[b]; });
    for(auto idx : ord)
        insert_frog(x[idx], x[idx] + len[idx], idx);
    for(int i = 0; i < m; i++) {
        ll p, b;
        cin >> p >> b;
        mos.insert({p, b});
        auto it = inverted.lower_bound({p, LLONG_MAX, 0});
        if(it == inverted.end())
            continue;
        if(it->r <= p) {
            int ps = it->idx;
            while(eat(ps)) {}
        }
    }
    for(int i = 0; i < n; i++)
        cout << win[i] << " " << len[i] << '\n';
}