#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

const int MAXN = 5e5 + 5;
gp_hash_table<int, pair<int, int>> pos;
ll BIT[MAXN];
set<int> best[30];

void upd(int p, ll v) {
    for(;p < MAXN; p += (p & -p))
        BIT[p] += v;
}

ll sum(int p) {
    ll res = 0;
    for(;p > 0; p -= (p & -p)) {
        res += BIT[p];
        if(res > 1e9)
            return res;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    vector<pair<int, ll>> queries(q);
    vector<int> vals;
    for(int i = 0; i < q; i++) {
        char c;
        ll val;
        cin >> c >> val;
        int t = (c == '+' ? 1 : -1);
        queries[i] = {t, val};
        if(c == '+')
            vals.push_back(val);
    }
    sort(vals.begin(), vals.end());
    int cnt = 0;
    while(cnt < vals.size()) {
        int v = vals[cnt];
        pos[v] = {cnt + 1, cnt + 1};
        while(vals[cnt] == v)
            cnt++;
    }
    set<int> ins;
    int amt = 0;
    for(pair<int, ll> qry : queries) {
        int w = qry.second;
        auto p = pos[w];
        if(qry.first == 1) {
            upd(p.second, w);
            if(p.second == p.first) {
                ins.insert(w);
                best[31 - __builtin_clz(w)].insert(w);
            }
            amt++;
            pos[w] = {p.first, p.second + 1};
        }
        else {
            upd(p.first, -w);
            pos[w] = {p.first + 1, p.second};
            amt--;
            if(p.first + 1 == p.second) {
                ins.erase(w);
                best[31 - __builtin_clz(w)].erase(w);
            }
        }
        int ans = amt;
        for(int i = 0; i < 30; i++) {
            if(best[i].empty())
                continue;
            ll w = *best[i].begin();
            if(w > 2ll*sum(pos[w].first - 1))
                ans--;
        }
        cout << ans << endl;
    }
}