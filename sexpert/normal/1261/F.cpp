    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef pair<ll, ll> ii;
     
    const ll MAX = (1ll << 60) - 1;
    const ll MOD = 998244353;
    vector<ii> segA, segB, lifA, lifB, fin;
    vector<vector<ii>> sA, sB, lA, lB;
     
    void lift(ll l, ll r, vector<ii> &res) {
        ll sz = r - l + 1;
        //cout << "start = " << l << " " << r << endl;
        while(sz <= MAX + 1) {
            res.push_back({l, r});
            if(l % (2LL*sz) == 0)
                r += sz;
            else
                l -= sz;
            sz *= 2;
        }
    }
     
    void decomp(ll l, ll r, ll rl, ll rr, vector<ii> &res, vector<ii> &lif) {
        if(rr < l || r < rl) return;
        if(rl <= l && r <= rr) {
            lift(l, r, lif);
            res.push_back({l, r});
            return;
        }
        ll m = (l + r)/2;
        decomp(l, m, rl, rr, res, lif);
        decomp(m + 1, r, rl, rr, res, lif);
    }
     
    void decomp(ll l, ll r, vector<ii> &res, vector<ii> &lif) {
        decomp(0, MAX, l, r, res, lif);
    }
     
    void clean(vector<ii> &v) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        v.shrink_to_fit();
    }
     
    void transfer(vector<ii> &seg, vector<vector<ii>> &fi) {
        fi.assign(62, vector<ii>());
        for(auto s : seg) {
            ll l = 63 - __builtin_clzll(s.second - s.first + 1);
            //cout << s.first << " " << s.second << " " << l << endl;
            fi[l].push_back(s);
        }
        seg.clear();
    }
     
    ii merge(ii s1, ii s2) {
        ll l = s1.first ^ s2.first;
        return {l, l + s1.second - s1.first};
    }
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
     
        int nA;
        cin >> nA;
        while(nA--) {
            ll l, r;
            cin >> l >> r;
            decomp(l, r, segA, lifA);
        }
        clean(segA), clean(lifA);
        int nB;
        cin >> nB;
        while(nB--) {
            ll l, r;
            cin >> l >> r;
            decomp(l, r, segB, lifB);
        }
        clean(segB), clean(lifB);
        //cout << "COMPLETED!" << endl;
        transfer(segA, sA);
        transfer(lifA, lA);
        transfer(segB, sB);
        transfer(lifB, lB);
        for(int s = 0; s < 62; s++) {
            for(auto s1 : sA[s])
                for(auto s2 : lB[s])
                    fin.push_back(merge(s1, s2));
            for(auto s1 : sB[s])
                for(auto s2 : lA[s])
                    fin.push_back(merge(s1, s2));
        }
        clean(fin);
        ll res = 0, cur = 0;
        map<ll, ll> di;
        vector<ll> pos;
        for(auto s : fin) {
            //cout << s.first << " " << s.second << endl;
            di[s.first]++;
            di[s.second + 1]--;
            pos.push_back(s.first);
            pos.push_back(s.second + 1);
        }
        sort(pos.begin(), pos.end());
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        for(int i = 0; i < pos.size() - 1; i++) {
            ll p = pos[i];
            cur += di[p];
            if(cur == 0)
                continue;
            ll q = pos[i + 1] - 1;
            p--;
            // [p, q)
            p %= MOD, q %= MOD;
            ll x = (q*(q + 1)/2 - p*(p + 1)/2) % MOD;
            res = (res + x) % MOD;
        }
        cout << (res + MOD) % MOD << '\n';
    }