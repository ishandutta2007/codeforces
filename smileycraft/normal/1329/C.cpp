
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

ll h, g, h2, g2;
vll v, d;
vector<bool> todo;

void execute(ll i){
    if (2 * i >= h2 || (v[2 * i] == 0 && v[2 * i + 1] == 0)){
        v[i] = 0;
        return;
    }
    if (v[2 * i] > v[2 * i + 1]){
        v[i] = v[2 * i];
        execute(2 * i);
    }
    else{
        v[i] = v[2 * i + 1];
        execute(2 * i + 1);
    }
    if (i >= g2) return;
    if (v[2 * i] > v[2 * i + 1]){
        if (v[2 * i] == 0 || !todo[2 * i]) todo[i] = false;
    }
    else{
        if (v[2 * i + 1] == 0 || !todo[2 * i + 1]) todo[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    ll T;
    cin >> T;
    while (--T >= 0){
        cin >> h >> g;
        h2 = 1LL << h;
        g2 = 1LL << g;
        v.assign(h2, 0);
        for (ll i = 1; i < h2; ++i) cin >> v[i];
        d.assign(h2, 0);
        for (ll depth = 1; depth <= h; ++depth) for (ll i = 1LL << (depth - 1); i < (1LL << depth); ++i) d[i] = depth;
        todo.assign(h2, true);
        vll output;
        for (ll i = 1; i < g2; ++i){
            while (todo[i]){
                output.push_back(i);
                execute(i);
            }
        }
        ll score = 0;
        for (ll i = 1; i < g2; ++i) score += v[i];
        cout << score << endl << output[0];
        for (ll i = 1; i < output.size(); ++i) cout << ' ' << output[i];
        cout << endl;
    }
    return 0;
}