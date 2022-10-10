#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int n;
ll m, p;
vector<ll> masks;
ll best;
ll cnt[1 << 16];

void check() {
    int id = rnd() % n;
    ll bms = masks[id];
    vector<ll> bitsz;
    for(ll b = 0; b < m; b++)
        if((bms >> b) & 1LL)
            bitsz.push_back(b);
    int cb = bitsz.size();
    if(cb == 0)
        return;

    /*cout << "ITERATION\n";
    cout << i << '\n';
    for(auto b : bitsz)
        cout << b << " ";
    cout << '\n';*/

    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) {
        ll rms = 0;
        for(int b = 0; b < cb; b++)
            if((masks[i] >> bitsz[b]) & 1LL)
                rms |= (1 << b);
        //cout << rms << '\n';
        cnt[rms]++;
    }

    for(int i = 0; i < cb; i++) {
        for(int ms = (1 << cb) - 1; ms >= 0; ms--) {
            if(!(ms & (1 << i)))
                cnt[ms] += cnt[ms ^ (1 << i)];
        }
    }

    for(int ms = 1; ms < (1 << cb); ms++) {
        ll rms = 0;
        if(cnt[ms] >= (n + 1)/2 && (best == 0 || __builtin_popcount(ms) > __builtin_popcountll(best))) {
            for(int b = 0; b < cb; b++)
                if((ms >> b) & 1LL)
                    rms |= (1LL << (bitsz[b]));
            //cout << i << " " << rms << " " << ms << " " << cnt[ms] << '\n';
            best = rms;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> p;

    for(int i = 0; i < n; i++) {
        ll x = 0;
        string s;
        cin >> s;
        for(ll b = 0; b < m; b++)
            x |= (ll(s[b] == '1') << b);
        masks.push_back(x);
    }
    //for(auto &m : masks)
    //    cout << m << '\n';
    for(int it = 0; it < 30; it++)
        check();

    for(ll i = 0; i < m; i++)
        cout << ((best >> i) & 1LL);
    cout << '\n';
}