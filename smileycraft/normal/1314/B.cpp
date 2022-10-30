
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    ll n, k;
    cin >> n >> k;
    if (k == 0){
        cout << 0 << endl;
        return 0;
    }
    ll N = 1LL << n;
    vll v(N);
    for (ll i = 0; i < k; ++i){
        ll x;
        cin >> x;
        v[x - 1] = 1;
    }
    ll total = 1;
    for (ll i = 0; 2 * i < N; ++i) if (v[2 * i] || v[2 * i + 1]) ++total;
    vll up(N / 2), down(N / 2), min_loss(N / 2, -1);
    for (ll i = 0; 2 * i < N; ++i){
        if (v[2 * i] && v[2 * i + 1]){
            up[i] = down[i] = 1;
        }
        else if (v[2 * i] || v[2 * i + 1]){
            down[i] = 1;
            min_loss[i] = 0;
        }
    }
    for (ll M = N / 4, gain = 1; M > 0; M /= 2, ++gain){
        vll nup(M), ndown(M), nmin_loss(M);
        for (ll i = 0; i < M; ++i){
            if (up[2 * i] || up[2 * i + 1]){
                nup[i] = ndown[i] = 1;
            }
            else if (down[2 * i] && down[2 * i + 1]){
                ndown[i] = 1;
                ll ml = min(min_loss[2 * i], min_loss[2 * i + 1]);
                if (2 * ml < gain){
                    nup[i] = 1;
                }
                else nmin_loss[i] = ml;
            }
            else if (down[2 * i] || down[2 * i + 1]){
                ll j = down[2 * i] ? 2 * i : 2 * i + 1;
                ndown[i] = 1;
                if (min_loss[j] + 1 == gain) nmin_loss[i] = gain;
                else if (2 * min_loss[j] < gain){
                    nup[i] = 1;
                }
                else nmin_loss[i] = min_loss[j];
            }
            total += nup[i] + 2 * ndown[i];
        }
        up = nup; down = ndown; min_loss = nmin_loss;
    }
    cout << total << endl;
    return 0;
}