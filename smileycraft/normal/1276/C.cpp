
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

int main(){
    ll n;
    cin >> n;

    vll rts(n + 1);
    for (ll i = 1; i * i <= n; ++i) for (ll x = i * i; x <= n; x += i) rts[x] = i;

    vll v(n);
    for (ll i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    vll w(n + 1);
    for (ll i = 0; i < n; ){
        ll j = i;
        while (j < n && v[i] == v[j]){
            ++j;
            ++w[j - i];
        }
        i = j;
    }
    for (ll x = 1; x <= n; ++x) w[x] += w[x - 1];

    for (ll x = n; ; --x) if (w[rts[x]] >= x){
        ll h = rts[x], w = x / rts[x];
        cout << x << endl << h << ' ' << w << endl;
        vvll retval(h, vll(w));
        ll i = 0, j = 0, k = 0;
        while (j < w && k < n){
            ll l = k;
            while (l < n && v[k] == v[l]) ++l;
            ll c = l - k;
            if (c >= rts[x]) for (ll index = 0; index < rts[x] && j < w; ++index){
                retval[i][(i + j) % w] = v[k];
                ++i;
                if (i == h){
                    i = 0;
                    ++j;
                }
            }
            k = l;
        }
        k = 0;
        while (j < w && k < n){
            ll l = k;
            while (l < n && v[k] == v[l]) ++l;
            ll c = l - k;
            if (c < rts[x]) for (ll index = 0; index < c && j < w; ++index){
                retval[i][(i + j) % w] = v[k];
                ++i;
                if (i == h){
                    i = 0;
                    ++j;
                }
            }
            k = l;
        }
        for (ll i1 = 0; i1 < h; ++i1){
            cout << retval[i1][0];
            for (ll i2 = 1; i2 < w; ++i2) cout << ' ' << retval[i1][i2];
            cout << endl;
        }
        break;
    }

    return 0;
}