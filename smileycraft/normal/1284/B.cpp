
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

ll INF = 1000000;

int main(){
    ll n;
    cin >> n;
    vll minis(n, 1000000), maxis(n), max_counts(INF + 2);
    vector<bool> has_ascent(n);
    ll ascent_count = 0;
    for (ll i = 0; i < n; ++i){
        ll len, last = INF;
        cin >> len;
        for (ll j = 0; j < len; ++j){
            ll x;
            cin >> x;
            minis[i] = min(minis[i], x);
            maxis[i] = max(maxis[i], x);
            has_ascent[i] = has_ascent[i] || last < x;
            last = x;
        }
        if (has_ascent[i]) ++ascent_count;
        else ++max_counts[maxis[i]];
    }
    for (ll i = INF; i >= 0; --i) max_counts[i] += max_counts[i + 1];
    ll total = 0;
    for (ll i = 0; i < n; ++i){
        if (has_ascent[i]) total += n;
        else total += max_counts[minis[i] + 1] + ascent_count;
    }
    cout << total << endl;
    return 0;
}